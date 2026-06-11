#include <stdio.h>
#include <math.h>
int main(){
  int A,B;
  double C,S,L,H;
  scanf("%d %d %lf",&A,&B,&C);
  C=C*M_PI/180;
  S=0.5*A*B*sin(C);
  L=A+B+sqrt((A*A)+(B*B)-2*A*B*cos(C));
  H=2*S/A;
  printf("%f %f %f\n",S,L,H);
  return 0;
}