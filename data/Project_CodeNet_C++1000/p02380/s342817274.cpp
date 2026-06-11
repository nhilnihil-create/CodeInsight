#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  double a, b, C;
  cin >> a >> b >> C;
  double S, L, h;
  S = a*b/2*sin(C*M_PI/180);
  L = a + b + sqrt(a*a+b*b-2*a*b*cos(C*M_PI/180));
  h = 2*S/a;
  cout << fixed << setprecision(10) << S << endl
       << L << endl
       << h << endl;
  return 0;
}