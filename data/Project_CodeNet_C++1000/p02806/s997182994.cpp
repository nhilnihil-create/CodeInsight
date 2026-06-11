#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  pair<string,int> p[n];
  for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;

  string s;
  cin >> s;

  bool ok = false;
  int ans = 0;

  for (int i = 1; i < n; ++i) {
    if (s == p[i-1].first) ok = true;
    if (ok) ans += p[i].second;
  }

  cout << ans << endl;

  return (0);
}
