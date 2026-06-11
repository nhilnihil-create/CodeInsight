#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
typedef pair<int, int> P;

signed main(){
  int n, m; cin >> n >> m;
  vector<vector<int> > G(n);
  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    G[u - 1].push_back(v - 1);
  }
  vector<vector<int> > dist(n, vector<int> (3, INF));
  int s, t; cin >> s >> t; --s; --t;
  dist[s][0] = 0;
  queue<P> que;
  que.push(P(s, 0));
  while(que.size()){
    P p = que.front(); que.pop();
    int now = p.first, step = p.second;
    for(auto next : G[now]){
      int next_step = step + 1;
      if(next_step == 3) next_step = 0;
      if(dist[next][next_step] > dist[now][step] + 1){
        dist[next][next_step] = dist[now][step] + 1;
        que.push(P(next, next_step));
      }
    }
  }
  int ans = dist[t][0];
  if(ans == INF) cout << -1 << endl;
  else cout << ans / 3 << endl;
}


