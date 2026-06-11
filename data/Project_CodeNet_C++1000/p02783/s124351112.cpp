#include <stdio.h>

int main() {
  int H, A;
  scanf("%d %d", &H, &A);
  printf("%d", (H - 1) / A + 1);
  return 0;
}