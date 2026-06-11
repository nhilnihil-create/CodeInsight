#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
  double a,b,c,s,l,h;
  static const double pi = 3.141592653589793;
  cin>>a>>b>>c;
  double rad = c/360*2*pi;
  h=b*sin(rad);
  s=a*h*1/2;
  l=sqrt(a*a+b*b-2*a*b*cos(rad)) + a + b;

  printf("%.10lf ",s);
  printf("%.10lf ",l);
  printf("%.10lf",h);

  return 0;
}