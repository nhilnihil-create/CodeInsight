#include <stdio.h>

int x, y;

int main() {
  scanf("%d%d", &x, &y);
  printf("%d %d %lf\n", x/y, x%y, (double)x/y);
  return 0;
}