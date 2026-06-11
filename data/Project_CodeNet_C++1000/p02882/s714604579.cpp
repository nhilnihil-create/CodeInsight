#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  long double a, b, x;
  cin >> a >> b >> x;
  long double ans;
  if (a * a * b < 2 * x)
    ans = atan2(2 * b - 2 * x / a / a, a);
  else
    ans = atan2(b, 2 * x / a / b);
  ans = ans * 180 / M_PI;
  printf("%.8llf\n", ans);
  return 0;
}