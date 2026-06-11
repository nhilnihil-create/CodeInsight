#include<stdio.h>

int main(){
  double r,are,circ;
  double pi=3.141592653589;
  scanf("%lf",&r);
  are = pi*r*r;
  circ =2*pi*r;
  printf("%f %f\n", are,circ);
}