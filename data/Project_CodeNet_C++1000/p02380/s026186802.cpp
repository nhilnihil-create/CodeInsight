#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main() {
  double a,b,c,PI = 3.14159265359;
  cin >> a >> b >> c;
  printf("%f\n",a*b*sin(PI/180.0*c)/2.0);
  printf("%f\n",a+b+sqrt(a*a+b*b-2*a*b*cos(PI/180.0*c)));
  printf("%f\n",b*sin(PI/180.0*c));
  return 0;
}
