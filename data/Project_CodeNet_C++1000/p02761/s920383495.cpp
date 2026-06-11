#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<pair<int,char>> c(m);
  for (int i = 0; i < m; ++i) cin >> c[i].first >> c[i].second;

  for (int i = 0; i < 10000; ++i) {
    string s = to_string(i);
    if (s.length() > n) break;

    if (s.length() == n) {
      bool ok = true;

      for (int i = 0; i < m; ++i) {
        if (c[i].first > s.length()) {
          ok = false;
          break;
        }
        if (s[c[i].first-1] != c[i].second) ok = false;
      }

      if (ok) {
        cout << s << '\n';
        return (0);
      }
    }
  }

  cout << -1 << '\n';

  return (0);
}