#include<bits/stdc++.h>
using namespace std;
using lint = long long;
typedef pair<lint, lint> P;

signed main(){
  lint N; cin >> N;
  vector<vector<lint> > G(N);
  vector<P> pa;
  for( lint i = 1; i < N; i++ ){
    lint a, b; cin >> a >> b; --a ;--b;
    G[a].push_back(b); G[b].push_back(a);
    pa.push_back(P(a, b));
  }

  queue<lint> que;
  vector<lint> used(N, -1);
  vector<lint> color(N, 0);
  map<P, lint> MAP;
  que.push(0); used[0] = 1;
  lint MAX_COLOR = 0;
  while(que.size()){
    lint v = que.front(); que.pop();
    lint num = 1;
    for( lint i = 0; i < G[v].size(); i++ ){
      lint next = G[v][i];
      if(used[next] != -1) continue;
      if(color[v] == num) num++;
      used[next] = 1;
      color[next] = num;
      MAP[P(next, v)] = num;
      MAP[P(v, next)] = num;
      num++;
      que.push(next);
    }
    MAX_COLOR = max(lint(G[v].size()), MAX_COLOR);
  }
  cout << MAX_COLOR << '\n';
  for(auto p : pa) cout << MAP[p] << '\n';
}