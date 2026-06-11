#include<stdio.h>

int main(void){
  int i,j,H,W;

  for(scanf("%d%d",&H,&W);H!=0||W!=0;scanf("%d%d",&H,&W)){
    for(i=0;i<H;i++){
      for(j=0;j<W;j++){
        putchar((i+j)%2?'.':'#');
      }
      putchar('\n');
    }
    putchar('\n');
  }
  return 0;
}