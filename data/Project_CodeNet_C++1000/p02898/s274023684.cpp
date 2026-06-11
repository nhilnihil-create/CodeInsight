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

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    int h;
    cin >> h;
    if (h >= k) ++ans;
  }

  cout << ans << endl;

  return (0);
}
