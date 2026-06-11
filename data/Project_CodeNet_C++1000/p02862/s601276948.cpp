#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)
typedef long long ll;
const ll MOD=1000000007;

ll calc(ll a,ll b){
  if(!b) return 1;
  if(b%2) return (a*calc(a,b-1))%MOD;
  ll d=calc(a,b/2);
  return (d*d)%MOD;
}

ll modcom(ll a,ll b){
  if(a<b) return 0;
  if(a/2<b) b=a-b;

  ll rtn=1;
  for(ll i=a;i>a-b;i--){
    rtn*=i;
    rtn%=MOD;
  }
  for(ll i=b;i>0;i--){
    rtn*=calc(i,MOD-2);
    rtn%=MOD;
  }
  return rtn;
}

int main(){
  ll x,y,ans=0;cin>>x>>y;
  ll n=2*y-x,m=2*x-y;
  if(!(n%3)&&!(m%3)&&n>=0&&m>=0) ans=modcom((n+m)/3,n/3);
  cout<<ans;
}