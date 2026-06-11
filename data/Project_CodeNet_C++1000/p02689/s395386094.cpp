/*input
4 3
1 2 3 4
1 3
2 3
2 4
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  vector<vector<int>> g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> cnt(n, 1);
  rep(i, n) for (int to: g[i]) {
    if (h[i] <= h[to]) cnt[i] = 0;
  }
  int ans = 0;
  rep(i, n) ans += cnt[i];
  cout << ans << endl;
  // rep(i, n) cout << h[i] << endl;
  return 0;
}