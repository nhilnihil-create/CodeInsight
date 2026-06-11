#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define ALL(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}

using Graph = vector<vector<int>>;

int main() {
  int N, M; cin >> N >> M;

  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
  }

  int s, t; cin >> s >> t;
  s--; t--;

  VV dist(N, V(3, INF));
  queue<P> que;
  dist[s][0] = 0;
  que.push(P(s, 0));
  while (!que.empty()) {
    int v, j;
    tie(v, j) = que.front(); que.pop();
    int jj = (j+1) % 3;
    for (auto nv : G[v]) {
      if (chmin(dist[nv][jj], dist[v][j] + 1)) {
        que.push(P(nv, jj));
      }
    }
  }

  if (dist[t][0] == INF) {
    cout << -1 << endl;
  }
  else {
    cout << (dist[t][0] / 3) << endl;
  }
  return 0;
}
