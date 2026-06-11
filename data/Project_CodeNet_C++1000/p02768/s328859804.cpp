#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll  MAX=510000;
const ll MOD=1000000007;
ll fanc[MAX],inv[MAX],finv[MAX];

//n^p(mod M)を繰り返し2乗法で求める
ll Repeat(ll n,ll p,ll m){
  if(p==0)return 1;
  if(p%2==0){
    ll t=Repeat(n,p/2,m);
    return t*t%m;
  }
  return n*(Repeat(n,p-1,m));
}
//前処理
void COMinit(){
  fanc[0]=fanc[1]=1;
  inv[1]=1;
  finv[0]=finv[1]=1;
  for(int i=2;i<MAX;i++){
    fanc[i]=fanc[i-1]*i%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}
//二項係数
ll COM(ll n,ll k){
  if(n<0||k<0)return 0;
  if(n<k)return 0;
  return fanc[n-k+1]*(finv[n-k]%MOD)%MOD;
}
int main(){
  COMinit();
  ll n,a,b;
  cin>>n>>a>>b;
  ll all=Repeat(2,n,MOD);
  ll v1 = 1;
  for (ll i = n; i > n - a; i--) {
        v1 *= i;
        v1 %= MOD;
  }
  ll v2 = 1;
  for (ll i = n; i > n - b; i--) {
      v2 *= i;
      v2 %= MOD;
    }  
  v1=v1*(finv[a]%MOD)%MOD;
  //cout<<v1<<endl;
  v2=v2*finv[b]%MOD;

  ll ans=all-1-v1-v2;
  while(ans<0){
    ans += MOD;
  }
    
    ans %= MOD;
  cout<<ans<<endl;
}
