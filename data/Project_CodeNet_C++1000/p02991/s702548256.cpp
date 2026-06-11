// https://atcoder.jp/contests/abc132/tasks/abc132_e
#include <bits/stdc++.h>
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;
typedef long long ll;

using Graph = vector<vector<int>>;
using pint = pair<int,int>;

int N,M;
Graph G;
int s,t;


void solve(){
  vector<vector<ll>> dist(N,vector<ll>(3,-1));
  queue<pint> que;
  dist[s][0] = 0;
  que.push(pint(s,0));

  while(!que.empty()){
    auto p = que.front();que.pop();
    int v = p.first;
    int parity = p.second;

    for(auto nv:G[v]){
      int nparity = (parity+1) % 3;
      if(dist[nv][nparity] == -1){
        dist[nv][nparity] = dist[v][parity] + 1;
        que.push(pint(nv,nparity));
      }
    }
  }

  if(dist[t][0] == -1) cout<< -1;
  else cout<< dist[t][0]/3;
}





int main(){
  cin>>N>>M;

  G.assign(N,vector<int>());

  rep(i,M){
    int u,v;
    cin>>u>>v;
    u--,v--;
    G[u].push_back(v);
  }
cin>>s>>t;
s--,t--;
  solve();
}
