#include <stdio.h>
int main(void){
  double a,b;
  scanf("%lf %lf",&a,&b);
  int aa=a,bb=b;
  printf("%d %d %lf\n",aa/bb,aa%bb,a/b);
  return 0;
}

