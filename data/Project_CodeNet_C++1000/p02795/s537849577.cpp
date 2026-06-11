#include <stdio.h>
 
int main() {
  int H, W, N, result;
  scanf("%d %d %d", &H, &W, &N);
  result = (H > W) ? (N+H-1)/H : (N+W-1)/W;
  printf("%d\n", result);
  return 0;
}