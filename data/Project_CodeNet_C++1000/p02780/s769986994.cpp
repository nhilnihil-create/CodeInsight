#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cout << fixed << setprecision(10);
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  vector<long double> p(n+1, 0);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;

    p[i] = ((x + 1) / 2.0) + p[i-1];
  }

  long double ans = 0;

  for (int i = 0; i < n-k+1; ++i) ans = max(ans, p[i+k] - p[i]);

  cout << ans << '\n';

  return (0);
}
