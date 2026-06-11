#include <stdio.h>

int main(){

  int i,x,y,m;
  for(i=1;i<=3000;i++){
    scanf("%d%d",&x,&y);
    if(x==0&&y==0) break;
    if(x>y){
      m=y;
      y=x;
      x=m;
    }
    printf("%d %d\n",x,y);
  }
  return 0;
}
  