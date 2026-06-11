#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll dfs(int now, int from, const vector<vector<int>> &G, int K) {
  // now以下の部分木を塗る場合の数を返す
  if (K < G[now].size()) {
    return 0;
  }
  int usable_color = from == -1 ? K - 1 : K - 2;
  ll res = 1;
  for (auto e : G[now]) {
    if (e == from)
      continue;
    res *= usable_color;
    usable_color--;
    res %= MOD;
    res *= dfs(e, now, G, K);
    res %= MOD;
  }
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> G(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ll ans = k * dfs(0, -1, G, k);
  ans %= MOD;
  cout << ans << endl;
}
