#include <stdio.h>

int main() {
  int H, W;
  int h, w;
  scanf("%d %d", &H, &W);
  while(H != 0 || W != 0) {
    for(h = 0; h < H; h++) {
      for(w = 0; w < W; w++) {
        if(h == 0 || h == H - 1 || w == 0 || w == W - 1) {
          printf("#");
        } else {
          printf(".");
        }
      }
      printf("\n");
    }
    printf("\n");
    scanf("%d %d", &H, &W);
  }
  return 0;
}