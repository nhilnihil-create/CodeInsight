#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  vector<vector<int>> G(N);
  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  const int64_t mod = 1e9 + 7;
  int64_t answer = K;
  queue<pair<int, int>> bfs;
  bfs.emplace(0, -1);
  while (!bfs.empty()) {
    int size = bfs.size();
    rep(i, size) {
      int u, from;
      tie(u, from) = bfs.front();
      bfs.pop();
      if (K < (int)G[u].size()) {
        cout << 0 << endl;
        return 0;
      }
      int col = (from == -1) ? K - 1 : K - 2;
      for (auto v : G[u]) {
        if (v == from) continue;
        answer *= col;
        answer %= mod;
        col--;
        bfs.emplace(v, u);
      }
    }
  }
  cout << answer << endl;
  return 0;
}
