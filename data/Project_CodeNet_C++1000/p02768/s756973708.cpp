#include<bits/stdc++.h>
using namespace std;
using ll=long long;
// 繰り返し2乗法
ll square_method(ll k,ll p,ll m){//k^p(mod m)
  if(p==0)return 1;
  if(p%2==0){
    ll t=square_method(k,p/2,m);
    return t*t%m;
  }
  return square_method(k,p-1,m)*k;
}
//二項定理
const ll MOD=1000000007;
const ll MAX=550000;
ll fanc[MAX],inv[MAX],finv[MAX];
void COMinit(){
  fanc[0]=fanc[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(ll i=2;i<MAX;i++){
    fanc[i]=fanc[i-1]*i%MOD;
    inv[i]=MOD-(MOD/i)*(inv[MOD%i])%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}
ll COM(ll n,ll k){
  if(n<k)return 0;
  if(n<0||k<0)return 0;
  return fanc[n]*(finv[n-k]*finv[k]%MOD)%MOD;
}
int main(){
  int n,a,b;
  cin>>n>>a>>b;
  COMinit();
  ll all=square_method(2,n,MOD);
  ll tmp1=1,tmp2=1;
  for(ll i=n;i>=n-a+1;i--){
    tmp1=tmp1*i%MOD;
  }
  //cout<<tmp1<<endl;
  for(ll i=n;i>=n-b+1;i--){
    tmp2=tmp2*i%MOD;
  }
  //cout<<all<<endl;
  tmp1=tmp1*finv[a]%MOD;
  tmp2=tmp2*finv[b]%MOD;
  ll ans=all-1-tmp1-tmp2;
  while(ans<0){
    ans+=MOD;
  }

  //ここエラーするよ~~~~~~~~~~~~~~~~
  ans=ans%MOD;
  //~~~~~~~~~~~~~~~~~~~~~~~~~
  cout<<ans<<endl;
  
}