#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
  int a, b, x;
  cin >> a >> b >> x;
  int jdg = a * a * b;
  ld ans;
  if (jdg == 2 * x) ans = 45.0;
  else if (jdg < 2 * x) {
    ans = atan(((2.0 * a * a * b) - 2 * x) / (a * a * a)) * 180 / acos(-1);
  } else {
    ans = atan(a * b * b / (2.0 * x)) * 180 / acos(-1);
  }

  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}
