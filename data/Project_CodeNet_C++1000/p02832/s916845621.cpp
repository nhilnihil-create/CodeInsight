#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int now = 1, ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == now) ++now;
    else ++ans;
  }

  if (ans == n) cout << -1 << '\n';
  else cout << ans << '\n';

  return (0);
}