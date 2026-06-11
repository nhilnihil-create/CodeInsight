#include <bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;

    if (u > v) swap(u, v);
    g[u].push_back(v);
  }
  
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += i * (i + 1) / 2;
  }
  for (int i = 0; i < n; ++i) {
    for (auto j : g[i]) {
      ans -= (i + 1) * (n - j);
    }
  }
  cout << ans << '\n';
}
