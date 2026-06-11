#include <stdio.h>
#include <math.h>

int main(){
  double a,b,c;
  double d , h, ang;
  double PI=acos(-1);

  scanf("%lf%lf%lf",&a,&b,&c);

  ang=c/180*PI;
  
  h = b * sin(ang);

  d = sqrt(pow(a,2) + pow(b,2) - 2 * a * b * cos(ang));

  printf("%f\n", a * h / 2);
  
  printf("%f\n",a + b + d);

  printf("%f\n",h);



  return 0;
}

