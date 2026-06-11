#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;

//a^b(mod p)をO(log b)で求める
ll calc(ll a,ll b){
  if(!b) return 1;
  if(b%2) return (a*calc(a,b-1))%MOD;
  ll d=calc(a,b/2);
  return (d*d)%MOD;
}

//aCb(mod MOD)
ll modcom(ll a,ll b){
  if(a<b) return 0; //a<bの場合は0
  if(a/2<b) b=a-b; //計算量削減

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
  ll n,k;cin>>n>>k;

  for(ll i=1;i<=k;i++){
    ll ans=modcom(n-k+1,i);
    ans*=modcom(k-1,i-1);
    ans%=MOD;
    cout<<ans<<endl;
  }
}
