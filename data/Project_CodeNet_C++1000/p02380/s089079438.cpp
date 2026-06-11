#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  int a, b, C;
  cin >> a >> b >> C;
  double rad = (C*acos(-1))/180.0;

  double S, L, h;
  S = (1/2.0)*a*b*sin(rad);
  L = a + b + sqrt(a*a + b*b - 2*a*b*cos(rad));
  h = b*sin(rad);
  printf("%lf\n%lf\n%lf\n", S, L, h);

return 0;
}