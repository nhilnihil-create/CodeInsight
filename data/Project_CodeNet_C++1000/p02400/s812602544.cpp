#include <stdio.h>
#include <math.h>
int main(void){
  double r,s,l;
  scanf("%lf",&r);
  l = M_PI * r * 2;
  s = r * r * M_PI;
  printf("%lf %lf\n",s,l);
  return 0;
}

