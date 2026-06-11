#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>
using namespace std;


int main(void) {
  double pi = 3.14159265358979;
  double a, b, c;
  cin >> a >> b >> c;

  double s = a * b * sin( c*pi / 180  ) / 2;
  double l = a + b + sqrt( a*a + b*b - 2*a*b*cos(c*pi / 180) );
  double h = b * sin( c * pi / 180 );

  printf("%.8lf\n", s);
  printf("%.8lf\n", l);
  printf("%.8lf\n", h);

  return 0;
}