#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979323846264338327950L

int main()
{
  long double a,b; // a short b long
  long double h,m; // h hort m minte
  cin >> a >> b >> h >> m;
  
  
  long double clen = (long double)(a * a + b * b) - (long double)(2.0 * a * b) * cos(PI * (h / 6.0 + (m / 360.0) - m / 30.0));
  
  cout << fixed;
  cout << setprecision(20);  
  cout << sqrtl(clen) << endl;
}