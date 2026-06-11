#include <bits/stdc++.h>

int main() {

  double a, b, C;

  std::cin >> a >> b >> C;
  
  double pi = 3.141592653689793238462643383279;
  double S = a*b*sin(C*2*pi/360)/2;
  double c = sqrt(a*a+b*b-2*a*b*cos(C*2*pi/360));

  printf("%.10lf\n", S);
  printf("%.10lf\n", a+b+c);
  printf("%.10lf\n", S*2/a);
  
  return 0;
}