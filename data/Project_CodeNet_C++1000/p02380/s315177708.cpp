#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
  int a,b,C;
  cin >> a >> b >> C;
  double Crad = C / 180.0 * M_PI;
  double cosC = cos(Crad);
  double sinC = sin(Crad);
  double c;
  c = sqrt( a*a + b*b -2*a*b*cosC);
  double L = a+b+c;
  double h = ( C == 90 ? b : ( sinC * b ) );
  double S = (a * b / 2.0) * sinC;
  printf("%.11lf\n", S);
  printf("%.11lf\n", L);
  printf("%.11lf\n", h);
}