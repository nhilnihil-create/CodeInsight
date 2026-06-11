#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,ll>;
using Graph= vector<vector<ll>>; 
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}

vector<ll> ans ;
vector<bool> seen ;
 void dfs(const Graph & G,ll v){
   seen[v]=true ;
   for(auto u: G[v] ){
   if(seen[u]) continue ;
   ans[u]+=ans[v] ;
   dfs(G,u) ;
 }
}
int main(){
ll n;cin>>n ;
 ll q ; cin>> q ;
 Graph g(n) ;
  rep(i,n-1){
    ll a,b ;
    cin>>a>>b ;
    a-- ;b-- ;
    g[a].pb(b) ;
    g[b].pb(a) ;
  }
  ans.resize(n) ;
  rep(i,q){
    int p,x ;
    cin>>p>> x ;
    p-- ;
    ans[p]+= x ;
  }
  
  seen.assign(n,false) ;
  
  dfs(g,0) ;
  rep(i,n) cout<<ans[i] <<endl ;
 return 0;
  }