#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll nC2(ll n)
{
  return n * (n - 1) / 2;
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int a[n];
  map<int,int> mp;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++mp[a[i]];
  }

  ll ans = 0;
  for (auto e : mp) ans += nC2(e.second);

  for (int i = 0; i < n; ++i) cout << ans - (mp[a[i]] - 1) << '\n';

  return (0);
}
