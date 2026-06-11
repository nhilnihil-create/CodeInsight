#include <stdio.h>

int main() {
  int H, W;
  int h, w;
  scanf("%d %d", &H, &W);
  while(H != 0 || W != 0) {
    for(h = 0; h < H; h++) {
      for(w = 0; w < W; w++) {
        if((w + h) % 2 == 0) printf("#");
        else printf(".");
      }
      printf("\n");
    }
    printf("\n");
    scanf("%d %d", &H, &W);
  }
  return 0;
}