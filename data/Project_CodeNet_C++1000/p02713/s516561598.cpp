#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int k;
  cin >> k;

  ll ans = 0;

  for (int a = 1; a <= k; ++a) {
    for (int b = 1; b <= k; ++b) {
      for (int c = 1; c <= k; ++c) {
        int gcd = __gcd(a, __gcd(b, c));
        ans += gcd;
      }
    }
  }
  
  cout << ans << '\n';

  return (0);
}
