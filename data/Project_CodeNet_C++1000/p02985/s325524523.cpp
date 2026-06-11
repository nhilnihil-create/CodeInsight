#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, M = 1e9+7;
  cin >> N >> K;
  vector<vector<int>> G(N);
  for (int a, b; cin >> a >> b;) {
    a--, b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }

  auto dfs = [&](auto f, int pre, int v) -> long {
    long ret = 1;
    int k = (pre == -1) ? K : K - 1;
    for (auto next : G.at(v)) {
      if (next == pre) continue;
      ret *= --k;
      ret %= M;
      ret *= f(f, v, next);
      ret %= M;
    }
    return ret;
  };

  cout << dfs(dfs, -1, 0) * K % M << "\n";
}
