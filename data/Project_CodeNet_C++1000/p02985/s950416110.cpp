#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
深さしらべて、3個ずつにぬれるいろの可能性をかけてくかんじ
1=K
2=K-1
むずかしい
DFSかな
DP?
子どもの数のデータはいる
1個ウエの親データ

6*5P2*(6-2)P3*...みたいな

1-2-4
 -3-5
   -6
*/
vector<bool> seen;
vector<vector<ll>> G;
vector<ll> C;
ll MOD=1e9+7,N,K;
queue<ll> Q;
struct UnionFind{
  vector<ll> par,siz;
  
  UnionFind(ll N):par(N+1),siz(N+1,1){
    for(int i=0; i<=N; i++)
      par[i]=i;
  }
  
  void mkpar1(ll parent, ll n){//親は最上位
    for(auto next_n: G[n]){
      if(seen[next_n]) continue;
      seen[next_n]=true;
      par[next_n]=parent;
      mkpar1(parent, next_n);
    }
  }
  
  void mkpar2(ll n){//親は1個うえ
    for(auto next_n: G[n]){
      if(seen[next_n]) continue;
      seen[next_n]=true;
      par[next_n]=n;
      mkpar2(next_n);
    }
  }
  
  ll root(ll x){
    if(par[x]==x)
      return x;
    return par[x]=root(par[x]);
  }
  
  void unite(ll x, ll y){
    ll rx=root(x), ry=root(y);
    if(rx==ry)
      return;
    par[ry]=rx;
    siz[rx]+=siz[ry];    
  }
  
  bool issame(ll x, ll y){
    return root(x)==root(y);
  }
  
  ll size(ll x){
    return siz[root(x)];
  }
};

ll bfs(){
  ll ans=K;
  while(!Q.empty()){
    ll v=Q.front();
    Q.pop();
    //子どもの数だけ組み合わせ
    for(ll i=0; i<C[v]; i++){
      if(v==1) (ans*=(K-1-i))%=MOD;
      else(ans*=(K-2-i))%=MOD;
    }
    //次の数いれる
    for(auto next_v: G[v]){
      if(seen[next_v]) continue;
      seen[next_v]=true;
      if(C[next_v]==0) continue;
      Q.emplace(next_v);
    }
  }
  return ans;
}
int main(){
  cin>>N>>K;
  seen.assign(N+1,false);
  C.assign(N+1,0);
  G.assign(N+1, vector<ll>(0,0));
  for(ll i=0; i<N-1; i++){
    ll a,b; cin>>a>>b;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  UnionFind tree(N);
  tree.mkpar2(1);
  //子どもの数
  for(ll i=2; i<=N; i++) C[tree.par[i]]++;
  seen.assign(N+1,false);
  Q.emplace(1);
  seen[1]=true;
  cout<<bfs()<<endl;
}