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
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int MAX = 3e5;

vector<int> G[MAX];
vector<int> d(MAX, -1);

void bfs(int s) {
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v: G[u]) {
      if (d[v] != -1) continue;
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
}


int main() {
  int n, m;
  cin >> n >> m;
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v + n);
    G[u + n].push_back(v + 2 * n);
    G[u + 2 * n].push_back(v);
  }
  int s, t;
  cin >> s >> t;
  s--, t--;

  bfs(s);
  cout << (d[t] == -1 ? -1 : d[t] / 3) << endl;



  



  
  return 0;
}