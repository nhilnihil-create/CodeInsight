#include <stdio.h>

int main() {
  unsigned long n = 0;
  unsigned long r = 1;
  scanf("%lu", &n);
  while(n >= r) {
    r <<= 1;
  }

  printf("%lu", r - 1);
}
