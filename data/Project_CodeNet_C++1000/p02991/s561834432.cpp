#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 100005;
const int INF = 1e8;

int n, m, s, t;

vector<int> G[N];
int dist[N][3];

int main() {
  cin >> n >> m;
  rep(i, m) {
    int u, v;
    cin >> u >> v; u--; v--;
    G[u].push_back(v);
  }
  cin >> s >> t; s--; t--;

  priority_queue<P, vector<P>, greater<P>> que;
  rep(i, n) rep(j, 3) dist[i][j] = INF;
  dist[s][0] = 0;
  que.push(make_pair(0, s));

  while (que.size()) {
    P p = que.top();
    que.pop();
    int d = p.first;
    int pos = p.second;
    rep(i, G[pos].size()) {
      int to = G[pos][i];
      int nd = d + 1;
      if (dist[to][nd % 3] > (nd + 2) / 3) {
        dist[to][nd % 3] = (nd + 2) / 3;
        que.push(make_pair(nd, to));
      }
    }
  }
  
  if (dist[t][0] == INF) cout << -1 << endl;
  else cout << dist[t][0] << endl;
  return 0;
}