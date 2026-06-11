#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  double a, b, C, angleC, S, L, h;
  cin >> a >> b >> C;
  angleC = C*M_PI/180;
  S = a*b*sin(angleC)/2;
  L = a + b + sqrt(a*a+b*b-2*a*b*cos(angleC));
  h = b*sin(angleC);

  cout << fixed << setprecision(5)
       << S << endl
       << L << endl
       << h << endl;
}