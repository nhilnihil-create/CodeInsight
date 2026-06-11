#include <stdio.h>

int main(void){
  int a,b;
  int x,y,z;
  

  scanf("%d %d",&a,&b);

  if (1 <= a,b <= 1000000000){
    x=a/b;
    y=a%b;
    double f;
    f=1.0*a/b;
    printf("%d %d %f\n",x,y,f);
  }
  return 0;
}