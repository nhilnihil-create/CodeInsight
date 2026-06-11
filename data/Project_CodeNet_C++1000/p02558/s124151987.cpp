#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*
連結かどうかを判定するのに探索してたら間に合わないかな
mapで間に合うか。
いや、連結なら、だったか・・・。unionか
*/
vector<vector<ll>> G;
vector<bool> seen;
struct UnionFind{
  vector<ll> par,siz;
  
  UnionFind(ll N):par(N+1),siz(N+1,1){
    for(int i=0; i<=N; i++)
      par[i]=i;
  }
  
  void mkpar(ll n, ll set){//親はset=根
    for(auto next_n: G[n]){
      if(seen[next_n]) continue;
      seen[next_n]=true;
      par[next_n]=set;
      mkpar(next_n, set);
    }
  }

  void mkpar2(ll n){//親は1個上、引数1個
    for(auto next_n: G[n]){
      if(seen[next_n]) continue;
      seen[next_n] = true;
      par[next_n] = n;
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

int main(){
  ll N, Q;
  cin >> N >> Q;
  G.assign(N+1, vector<ll>());
  seen.assign(N+1,false);
  UnionFind tree(N);
  for(int i = 0; i < Q; i++){
    ll t, u, v;
    cin >> t >> u >> v;
    if (t == 0){
      G[u].emplace_back(v);
      G[v].emplace_back(u);
      tree.unite(u, v);
    }
    else {
      if (tree.issame(u, v))
        cout << 1 << endl;
      else
        cout << 0 << endl;
    }
  }
}