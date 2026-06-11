#include<stdio.h>

int main(){
  int a=0,b=0,d=0,r=0;
  double f;

  scanf("%d %d",&a,&b);

    d=a/b;
  printf("%d ",d);
    
    r=a%b;
    printf("%d ",r);

    f=(double)a/(double)b;
  printf("%f\n",f);
  return 0;

}