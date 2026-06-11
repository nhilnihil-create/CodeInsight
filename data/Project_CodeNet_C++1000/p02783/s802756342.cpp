#include <stdio.h>

int main() {
  int H, A, ctr = 0;
  scanf("%d %d", &H, &A);

  while(H > 0) {
    H -= A;
    ctr++;
  }
  printf("%d", ctr);
  return 0;
}