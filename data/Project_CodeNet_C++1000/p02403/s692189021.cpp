#include <stdio.h>

int main() {
  int W, H;
  int w, h;
  scanf("%d %d", &H, &W);
  while(W != 0 || H != 0) {
    for(h = 0; h < H; h++) {
      for(w = 0; w < W; w++) {
        printf("#");
      }
      printf("\n");
    }
    printf("\n");
    scanf("%d %d", &H, &W);
  }
  return 0;
}