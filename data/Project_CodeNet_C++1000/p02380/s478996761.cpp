#include<stdio.h>
#include<math.h>
int main(){
  double S,L,h,x,y;
  int a,b,c;
  double pai=3.141592653589;

  scanf("%d %d %d",&a,&b,&c);

  x=c*pai/180;
  y=sqrt(a*a+b*b-2*a*b*cos(x));
  h=b*sin(x);
  printf("%.8lf\n%.8lf\n%.8lf\n",h*a/2,a+b+y,h);

  return 0;
}