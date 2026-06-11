#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<ll> a(n), s(n+1, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) s[i+1] += s[i] + a[i];

  ll ans = 1e18;
  for (int i = 1; i < n; ++i) ans = min(ans, abs(s[i] - (s[n] - s[i])));

  cout << ans << endl;

  return (0);
}
