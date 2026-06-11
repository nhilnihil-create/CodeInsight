#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  int h[n];
  for (int i = 0; i < n; ++i) cin >> h[i];

  int mx[n];
  memset(mx, 0, sizeof(mx));

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;

    mx[a] = max(mx[a], h[b]);
    mx[b] = max(mx[b], h[a]);
  }

  int ans = 0;

  for (int i = 0; i < n; ++i) if (h[i] > mx[i]) ++ans;

  cout << ans << '\n';

  return (0);
}
