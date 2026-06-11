#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                           \
  cerr << __LINE__ << ": " << #x << " = {";        \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];        \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

struct StronglyConnectedComponents {
  vector<vector<int>> adj;

  StronglyConnectedComponents(int n) : adj(n) {}
  void add_edge(int src, int dst) { adj[src].push_back(dst); }
  pair<vector<vector<int>>, vector<int>> get_SCC() {
    vector<vector<int>> scc;
    vector<int> S, B, index(adj.size());
    function<void(int)> dfs = [&](int u) {
      B.push_back(index[u] = S.size());
      S.push_back(u);
      for (int v : adj[u]) {
        if (!index[v])
          dfs(v);
        else
          while (index[v] < B.back()) B.pop_back();
      }
      if (index[u] == B.back()) {
        scc.push_back({});
        B.pop_back();
        for (; index[u] < (int)S.size(); S.pop_back()) {
          scc.back().push_back(S.back());
          index[S.back()] = adj.size() + scc.size();
        }
      }
    };
    for (size_t u = 0; u < adj.size(); u++)
      if (!index[u]) dfs(u);
    reverse(scc.begin(), scc.end());
    for (size_t u = 0; u < adj.size(); u++)
      index[u] = scc.size() - index[u] + adj.size();
    return make_pair(scc, index);
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int node[N][N];
  int M = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < i; j++) node[i][j] = node[j][i] = M++;
  debug(M);
  StronglyConnectedComponents graph(M);
  for (int i = 0; i < N; i++) {
    int prev = -1;
    for (int j = 0; j < N - 1; j++) {
      int A;
      cin >> A;
      int v = node[i][--A];
      if (prev != -1) graph.add_edge(prev, v);
      prev = v;
    }
  }
  auto scc = graph.get_SCC();
  auto id = scc.second;
  if ((int)scc.first.size() < M) {
    cout << -1 << '\n';
  } else {
    int dp[M];
    fill(dp, dp + M, 1);
    int ans = 0;
    for (int i = 0; i < M; i++) {
      int v = scc.first[i][0];
      for (int u : graph.adj[v]) {
        int j = id[u];
        dp[j] = max(dp[j], dp[i] + 1);
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
