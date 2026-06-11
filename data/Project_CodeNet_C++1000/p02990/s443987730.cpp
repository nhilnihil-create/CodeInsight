#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
ll mod=1000000007;
ll K(ll x){
  ll i,res=1;REP(i,x){res*=i+1;res%=mod;}
  return res;
}
ll G(ll x){
  ll res=1,j=mod-2,n=x;
  while(j){
    if(j%2)res*=n;n*=n;j/=2;res%=mod;n%=mod;
  }
  return res;
}
ll COM(ll x,ll y){
  if(x<y)return 0;
  return K(x)*G(K(y)*K(x-y)%mod)%mod;
}
signed main(){
  ll N,K,i;cin>>N>>K;FOR(i,1,K+1)cout<<COM(K-1,i-1)*COM(N-K+1,i)%mod<<endl;
  return 0;
}