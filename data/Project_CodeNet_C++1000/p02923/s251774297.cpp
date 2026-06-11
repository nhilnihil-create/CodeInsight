#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];

  int now = h[0], ans = 0, stroke = 0;
  for (int i = 1; i < n; ++i) {
    if (now >= h[i]) ++stroke;
    else {
      ans = max(ans, stroke);
      stroke = 0;
    }

    now = h[i];
  }

  cout << max(ans, stroke) << endl;

  return (0);
}
