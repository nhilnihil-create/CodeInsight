#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
signed main(){
  ll N,i,j,ans=0;cin>>N;ll x[N],y[N];REP(i,N)cin>>x[i]>>y[i];map<P,ll>W;
  REP(i,N)REP(j,N)if(i!=j)W[P(x[i]-x[j],y[i]-y[j])]++;
  for(auto k:W)ans=max(ans,k.S);
  cout<<N-ans<<endl;
  return 0;
}