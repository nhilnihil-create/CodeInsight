#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define WHITE 0
#define CANDIDATE 1
#define VISITED 2

void topo(vvi &g, vi &id, vi &c, vi &o, int n) {
  queue<int> q;
  q.push(n);

  while (!q.empty()) {
    int u = q.front(); q.pop();
    
    o.push_back(u);
    c[u] = VISITED;
    
    for (auto x: g[u]) {
      id[x]--;
      if (!id[x] && c[x] == WHITE) {
        c[x] = CANDIDATE;
        q.push(x);
      }
    }
  }
}

int main() {
  int v, e, s, t;
  cin >> v >> e;
  
  vvi g(v);
  vi id(v), c(v, WHITE), o;
  rep(i, e) {
    cin >> s >> t;
    g[s].push_back(t);
    id[t]++;
  }
  
  rep(i, v) 
    if (!id[i] && c[i] == WHITE) topo(g, id, c, o, i);
  
  rep(i, v) cout << o[i] << endl;
}


