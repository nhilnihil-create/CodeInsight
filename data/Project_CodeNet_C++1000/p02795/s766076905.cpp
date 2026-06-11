#include <stdio.h>
 
int main() {
  int H, W, N;
  scanf("%d %d %d", &H, &W, &N);
  (H > W) ? printf("%d",(N+H-1)/H) : printf("%d",(N+W-1)/W);
  return 0;
}