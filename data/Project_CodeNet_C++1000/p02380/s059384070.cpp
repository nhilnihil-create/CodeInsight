#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(void)
{
  double a,b,c, S,L,H, pi=3.141592653589293;

  cin >> a >> b >> c;
  S = a*b*sin(c/180*pi)/2;
  L = a + b + sqrt(a*a+b*b-2*a*b*cos(c/180*pi));
  H = 2*S/a;
  cout << fixed << setprecision(6) << S << endl;
  cout << fixed << setprecision(6) << L << endl;
  cout << fixed << setprecision(6) << H << endl;
   
  return 0;
}