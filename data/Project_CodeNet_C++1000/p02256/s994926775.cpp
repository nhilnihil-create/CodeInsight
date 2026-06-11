#include<stdio.h>

int main (void) {
  int x, y, a, b, temp;
  scanf("%d %d", &x, &y);

  if (x > y) {
    a = x;
    b = y;
  } else {
    a = y;
    b = x;
  }

  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }

  printf("%d\n", a);

  return 0;
}