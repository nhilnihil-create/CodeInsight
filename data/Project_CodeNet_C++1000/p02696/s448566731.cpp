#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
  int a, ans;
  ll b, n;
  cin >> a >> b >> n;
  ll x = min(b - 1, n);
  ans = floor(a * x * 1.0 / b) - a * floor(x * 1.0 / b);

  cout << ans << endl;

  return 0;
}
