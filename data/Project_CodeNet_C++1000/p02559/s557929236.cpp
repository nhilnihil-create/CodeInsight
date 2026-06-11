#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
signed main(){
  ll N,Q,i;cin>>N>>Q;fenwick_tree<ll> F(N);
  REP(i,N){ll x;cin>>x;F.add(i,x);}
  REP(i,Q){
    ll x,u,v;cin>>x>>u>>v;
    if(x==0)F.add(u,v);
    else cout<<F.sum(u,v)<<endl;
  }
  return 0;
}