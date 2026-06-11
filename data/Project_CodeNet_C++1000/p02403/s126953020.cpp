#include <stdio.h>

int main(){
  int H, W;
  scanf("%d %d",&H ,&W);

  int i, j;
  while(1)
  {
    if(H == 0 && W == 0){
      break;
    }
    else{
      for(i = 0; i < H; ++i){
        for (j = 0; j < W; ++j) {
          printf("#");
        }
        printf("\n");
      }
    }
    printf("\n");
    scanf("%d %d",&H ,&W);
  }

  return 0;
}