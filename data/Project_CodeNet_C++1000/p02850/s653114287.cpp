#include<bits/stdc++.h>

using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

using ll = long long;
using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;

Graph G;

void dfs(int v, int p, int pc, vector<int> &res){
  int color = 1;
  if(color==pc) color++;
  
  for(auto e:G[v]){
    if(e.first==p) continue;
    res[e.second] = color;
    
    dfs(e.first, v, color, res);
    color++;
    if(color==pc) color++;
  }
}



int main(){
  int N;
  cin >> N;
  
  G.assign(N, vector<Edge>());
  
  for(int i=0; i<N-1; i++){
    ll a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b, i);
    G[b].emplace_back(a, i);
  }
  
  int max_color = 0;
  for(int i=0; i<N; i++) chmax(max_color, (int)G[i].size());
  
  vector<int> res(N-1, -1);
  dfs(0,-1, -1, res);
  
  cout << max_color << endl;
  for(auto v: res) cout << v << endl;

  return 0;
}