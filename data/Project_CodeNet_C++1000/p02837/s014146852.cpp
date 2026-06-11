#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<vector<pair<int,int>>> state(n);

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    for (int j = 0; j < a; ++j) {
      int x, y;
      cin >> x >> y;

      state[i].emplace_back(x-1, y);
    }
  }

  int ans = 0;

  for (int bit = 0; bit < (1<<n); ++bit) {
    vector<int> honest;
    for (int i = 0; i < n; ++i) if (bit & (1<<i)) honest.emplace_back(i);

    bool ok = true;
    for (auto p : honest) {
      for (auto s : state[p]) {
        if (s.second && find(honest.begin(), honest.end(), s.first) == honest.end()) ok = false;
        else if (s.second == 0 && find(honest.begin(), honest.end(), s.first) != honest.end()) ok = false;
      }
    }

    if (ok) ans = max(ans, (int)honest.size());
  }

  cout << ans << '\n';

  return (0);
}