#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int main(){
  int N; cin >> N;
  vector<vector<int> > G(N);
  vector<P> vec;
  for( int i = 1; i < N; i++ ){
    int a, b; scanf("%d%d", &a, &b); --a; --b;
    G[a].push_back(b); G[b].push_back(a);
    vec.push_back(P(a, b));
  }
  vector<int> used(N, -1), color(N, 0);
  map<P, int> MAP;
  queue<int> que;
  int MAX_COLOR = 0;
  used[0] = 1; que.push(0);
  while( que.size() ){
    int v = que.front(); que.pop();
    int num = 1;
    for( int i = 0; i < G[v].size(); i++ ){
      int u = G[v][i];
      if( used[u] != -1 ) continue;
      if( color[v] == num ) num++;
      color[u] = num;
      used[u] = 1;
      MAP[P(u, v)] = MAP[P(v, u)] = num;
      que.push(u);
      num++;
    }
    MAX_COLOR = max( MAX_COLOR, int(G[v].size()) );
  }
  cout << MAX_COLOR << '\n';
  for( auto p : vec ) cout << MAP[p] << '\n';
}