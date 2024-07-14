/*
 * replace-byte
 */

#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
  if (i < 0) {
    printf("error: i is negetive\n");
    return x;
  }
  if (i > sizeof(unsigned)-1) {
    printf("error: too big i");
    return x;
  }

  int byte_bits = 8;
  unsigned mask = ((unsigned) 0xFF) << (i * byte_bits);
  unsigned pos_byte = ((unsigned) b) << (i * byte_bits);

  return (x & ~mask) | pos_byte;
}

int main(int argc, char *argv[]) {
  unsigned rep_0 = replace_byte(0x12345678, 0, 0xAB);
  unsigned rep_3 = replace_byte(0x12345678, 3, 0xAB);
  printf("%X %X", rep_0, rep_3);
  return 0;
}
