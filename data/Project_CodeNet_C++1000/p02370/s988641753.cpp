#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define REPR(i, m, n) for (int i = (int)(m); i >= (int)(n); i--)
#define all(v) v.begin(), v.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using Graph = vector<vector<int> >;
vector<bool> seen;
vector<int> order;
vector<int> indeg;

void bfs(const Graph &G, int u){
  queue<int> q;
  q.push(u);
  while(!q.empty()){
    int v = q.front(); q.pop();
    seen[v] = true;
    order.push_back(v);
    for(int nv : G[v]){
      indeg[nv]--;
      if(seen[nv]) continue;
      if(indeg[nv] != 0) continue;
      q.push(nv);
    }
  }
}

int main(){
  int n, e; cin >> n >> e;

  indeg.assign(n, 0);
  Graph G(n);
  rep(i, e){
    int s, t; cin >> s >> t;
    G[s].push_back(t);
    indeg[t]++;
  }

  seen.assign(n, false);
  order.clear();
  rep(i, n){
    if(indeg[i] == 0 && !seen[i]) bfs(G, i);
  }

  rep(i, n) cout << order[i] << endl;

  return 0;
}




