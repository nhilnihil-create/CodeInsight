#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
//const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

vector<vector<int>> G;

vector<int> topsort(int n, vector<vector<int>> G) {
  vector<int> vs, indeg(n, 0);
  rep(v, n) for (int u: G[v]) indeg[u]++;
  queue<int> q;
  vector<bool> visited(n, false);
  rep(i, n) {
    if (indeg[i] || visited[i]) continue;
    q.push(i);
    while (q.size()) {
      int v = q.front();
      q.pop();
      if (visited[v]) continue;
      vs.push_back(v);
      visited[v] = true;
      for (int u: G[v]) {
        if (visited[u]) continue;
        if (--indeg[u] == 0 && !visited[u]) q.push(u);
      }
    }
  }
  return vs;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int n, m;
  cin >> n >> m;
  G.resize(n);
  rep(i, m) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
  }

  vector<int> ans = topsort(n, G);
  rep(i, n) cout << ans[i] << '\n';

  
  return 0;
}
