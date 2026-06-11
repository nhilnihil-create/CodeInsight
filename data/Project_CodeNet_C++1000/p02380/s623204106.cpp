#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main(){
  double a, b, c, cRad; //radian
  double s, l, h;
  double pi = acos(-1); // pi = 3.1415926535...
  
  cin >> a >> b >> cRad;

  s = a * b * sin(pi / 180 * cRad) / 2;
  c = sqrt( a*a + b*b - 2 * a * b * cos(pi / 180 * cRad) );
  l = a + b + c;
  h = 2 * s / a;
  
  printf("%f\n%f\n%f\n", s, l, h);
  
  return 0;
}