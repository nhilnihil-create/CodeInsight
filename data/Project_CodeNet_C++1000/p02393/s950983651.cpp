#include<stdio.h>

int main(){
  int a,b,c,x,y,z,e,f,g;
  scanf("%d%d%d",&a,&b,&c);
  x=a,y=b,z=c;
  if(x>y){
    x=b,y=a;
  }
  if(y>z){
    z=y,y=c;
    if(x>y){
      y=x,x=c;
    }
  }
  printf("%d %d %d\n",x,y,z);
}