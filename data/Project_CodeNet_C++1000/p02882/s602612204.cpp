#include <bits/stdc++.h>
using namespace std;

int main()
{
  double a, b, x;
  cin >> a >> b >> x;
  double theta;
  if (x <= a * a * b / 2.0)
  {
    theta = atan(a * b * b / (2.0 * x)) * 180.0 / M_PI;
  }
  else
  {
    theta = atan(2 * (a * a * b - x) / (a * a * a)) * 180.0 / M_PI;
  }
  printf("%.10f\n", theta);
}