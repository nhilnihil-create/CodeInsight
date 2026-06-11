#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

using P = pair<int, int>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> e(n);
  rep(i, m) {
    int u, v; cin >> u >> v; u--; v--;
    e[u].push_back(v);
  }

  int s, t; cin >> s >> t; s--; t--;

  vector<vector<int>> d(n, vector<int>(3, INF));
  queue<P> q;
  q.push({s, 0});
  d[s][0] = 0;

  while (!q.empty()) {
    int v = q.front().first;
    int l = q.front().second;
    q.pop();
    for (auto& u : e[v]) {
      int nl = (l + 1) % 3;
      if (d[u][nl] != INF) continue;
      d[u][nl] = d[v][l] + 1;
      q.push({u, nl});
    }
  }

  if (d[t][0] == INF) cout << -1 << endl;
  else cout << d[t][0] / 3 << endl;

  return 0;
}
