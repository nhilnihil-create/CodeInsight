#include<stdio.h>

int main(void){
  int i,j,H,W;

  for(scanf("%d%d",&H,&W);H!=0||W!=0;scanf("%d%d",&H,&W)){
    for(i=0;i<H;i++){
      for(j=0;j<W;j++){
        if(i==0||i==H-1||j==0||j==W-1)putchar('#');
        else putchar('.');
      }
      putchar('\n');
    }
    putchar('\n');
  }
  return 0;
}