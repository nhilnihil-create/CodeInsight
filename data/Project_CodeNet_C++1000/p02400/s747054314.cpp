#include<stdio.h>

int main(){
  double r=0,S,R;

  scanf("%lf",&r);

  S=(double)r*r*3.141592653589;
  printf("%f ",S);

  R=2*3.141592653589*r;
  printf("%f\n",R);
  return 0;

}