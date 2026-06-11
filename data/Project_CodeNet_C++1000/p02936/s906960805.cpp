//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;
ll INF=1e10;
vector<ll>cnt(1e7);
Graph G(1e7);
void dfs(ll v,ll p){
    for(auto nv:G[v]){
        if(nv==p)continue;
        cnt[nv]+=cnt[v];
        dfs(nv,v);
    }
}
int main(){
  ll n,q; cin>>n>>q;
  G.resize(n);
  rep(i,n-1){
      ll a,b; cin>>a>>b;
      a--;b--;
      G[a].push_back(b);
      G[b].push_back(a);
  }
  cnt.resize(n);
  rep(i,q){
      ll p,q; cin>>p>>q;
      p--;
      cnt[p]+=q;
  }
  dfs(0,-1);
  rep(i,n){
      cout<<cnt[i]<<" ";
  }
  cout<<endl;
}

























































































