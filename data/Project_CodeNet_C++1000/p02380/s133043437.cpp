#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>

using namespace std;


int main()
{
  double a, b, c, h, s, l;
  cin >> a >> b	>> c;
  h = sin(c / 360.0 * 2 * M_PI) * b;
  s = a	* h / 2.0;
  l = a	+ b + sqrt(pow(h, 2) + pow(a - cos(c / 360 * 2 * M_PI) * b, 2));
  printf("%lf\n%lf\n%lf\n", s, l, h);
  return 0;
}