#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i,m) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].emplace_back(v);
  }
  int s, t;
  cin >> s >> t;
  s--; t--;

  vector<vector<int>> dp(n, vector<int>(3, INF));
  queue<P> que;
  dp[s][0] = 0;
  que.push(make_pair(s, 0));
  while (!que.empty()) {
    auto e = que.front(); que.pop();
    int u = e.first;
    int cur = e.second;
    for (auto v : g[u]) {
      if (dp[v][(cur + 1) % 3] != INF) continue;
      dp[v][(cur + 1) % 3] = dp[u][cur] + 1;
      que.push(make_pair(v, (cur + 1) % 3));
    }
  }
  cout << (dp[t][0] == INF ? -1 : dp[t][0] / 3) << endl;
  return 0;
}
