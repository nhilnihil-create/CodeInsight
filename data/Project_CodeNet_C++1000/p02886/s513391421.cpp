#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> d(n);
  for (int i = 0; i < n; ++i) cin >> d[i];

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      ans += d[i] * d[j];
    }
  }

  cout << ans << endl;

  return (0);
}
