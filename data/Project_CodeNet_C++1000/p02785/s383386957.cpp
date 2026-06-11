#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  ll h[n];
  for (int i = 0; i < n; ++i) cin >> h[i];

  sort(h, h+n, greater<ll>());
  for (int i = 0; i < min(k, n); ++i) h[i] = 0;

  cout << accumulate(h, h+n, 0LL) << '\n';

  return (0);
}
