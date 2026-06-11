#include <bits/stdc++.h>
using namespace std;

int main()
{
  long double a, b, x, ans;
  cin >> a >> b >> x;
  long double c = a * a * b * 0.5;
  if (c >= x)
  {
    long double l = (2.0 * x) / (a * b);
    ans = atanl((long double)(b / l)) * 180.0 / M_PI;
  }
  else
  {
    int64_t y = (a * a * b) - x;
    long double l = (2.0 * y) / (a * a);
    ans = atanl((long double)(l / a)) * 180.0 / M_PI;
  }
  cout << fixed << setprecision(10) << ans << endl;
}