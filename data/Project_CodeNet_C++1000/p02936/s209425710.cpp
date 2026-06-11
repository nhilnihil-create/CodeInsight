#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define eb emplace_back
using ll=long long;
using vi=vector<ll>;

vi tree[200005],score(200005,0);
void dfs(ll p,ll x){
  for(ll k:tree[p]){
    if(k!=x){
      score[k]+=score[p];
      dfs(k,p);
    }
  }
  return;
}
void solve(){
  ll n,q;
  cin>>n>>q;
  rep(i,n-1){
    ll a,b;
    cin>>a>>b;
    tree[a-1].eb(b-1);
    tree[b-1].eb(a-1);
  }
  rep(i,n) score[i]=0;
  rep(i,q){
    ll p,x;
    cin>>p>>x;
    score[p-1]+=x;
  }
  dfs(0,-1);
  cout<<score[0];
  REP(i,1,n) cout<<" "<<score[i];
  cout<<'\n';
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
