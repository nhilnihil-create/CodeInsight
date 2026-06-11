#include<stdio.h>

int main(void){
  int i,j,H,W;

  scanf("%d%d",&H,&W);
  while(H!=0||W!=0){
    for(i=0;i<H;i++){
      for(j=0;j<W;j++){
        putchar('#');
      }
      putchar('\n');
    }
    putchar('\n');
    scanf("%d%d",&H,&W);
  }
  return 0;
}