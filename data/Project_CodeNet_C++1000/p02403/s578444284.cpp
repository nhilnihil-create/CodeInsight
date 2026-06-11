#include <stdio.h>
int H,W,i,j;
int main(){
  for(;;){
    scanf(" %d %d",&H,&W);
    if(H==0&&W==0){
      return 0;
    }
    for(i=0;i<H;i++){
      for(j=0;j<W;j++){
        printf("#");
      }
      printf("\n");
    }
    printf("\n");
  }
}