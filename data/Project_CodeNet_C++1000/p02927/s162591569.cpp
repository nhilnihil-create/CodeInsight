#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int m, d;
  cin >> m >> d;

  int ans = 0;
  for (int i = 22; i <= d; ++i) {
    int d1 = i % 10;
    int d2 = i / 10;

    if (d1 < 2 || d2 < 2) continue;
    if (d1 * d2 <= m) ++ans;
  }

  cout << ans << endl;

  return (0);
}
