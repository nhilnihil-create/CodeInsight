#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<ll>> G;
queue<pair<ll,ll>> Q;
vector<bool> used;
ll N,M,S,T;
/*
深さ3でマーキング、同じなら削除、のBFSいけそう
メモリ制限とかTLEとか。散々。
途中での絞込みも必要か
*/
ll bfs(ll T){
  ll cnt2=0;
  vector<bool> used2;
  while(!Q.empty()){
    auto now=Q.front();
    ll p=now.first;
    ll cnt=now.second;
    if(cnt2<cnt){
      used2.assign(N+1,false);
      cnt2=cnt;
    }
    Q.pop();
    for(auto v: G[p]){
      if(cnt%3==0){
        if(used[v]) continue;
        else if(v==T) return (cnt/3);
        used[v]=true;
      }
      else{
        if(used2[v]) continue;
        used2[v]=true;
      }
      Q.emplace(make_pair(v,cnt+1));
    }
  }
  return -1;
}

int main(){
  cin>>N>>M;
  used.assign(N+1,false); 
  G.assign(N+1,vector<ll>(0,0));
  for(ll i=0; i<M; i++){
    ll u,v; cin>>u>>v;
    G[u].emplace_back(v);
  }
  cin>>S>>T;
  Q.emplace(make_pair(S,1));
  used[S]=true;
  cout<<bfs(T)<<endl;
}