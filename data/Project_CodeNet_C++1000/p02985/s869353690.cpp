#include <bits/stdc++.h>
using namespace std;

int N, K, MOD = 1e9+7;
vector<vector<int>> G;

long dfs(int pre, int v) {
  long ret = 1;
  int k = (pre == -1) ? K : K - 1;
  for (auto next : G.at(v)) {
    if (next == pre) continue;
    ret *= --k;
    ret %= MOD;
    ret *= dfs(v, next);
    ret %= MOD;
  }
  return ret;
}

int main() {
  cin >> N >> K;
  G.resize(N);
  for (int a, b; cin >> a >> b;) {
    G.at(--a).push_back(--b);
    G.at(b).push_back(a);
  }
  cout << dfs(-1, 0) * K % MOD << "\n";
}
