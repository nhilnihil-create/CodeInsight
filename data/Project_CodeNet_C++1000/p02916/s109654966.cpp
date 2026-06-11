#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> a(n), b(n), c(n-1);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < n-1; ++i) cin >> c[i];

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += b[a[i]-1];
    if (i && (a[i] - a[i-1]) == 1) ans += c[a[i-1]-1];
  }

  cout << ans << endl;

  return (0);
}
