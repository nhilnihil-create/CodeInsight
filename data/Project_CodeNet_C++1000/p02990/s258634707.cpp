#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e+9+7;
const ll MAX_V=2900;
ll N,K;
ll fanc[MAX_V],inv[MAX_V],finv[MAX_V];
void COMinit(){
  fanc[0]=fanc[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(ll i=2;i<MAX_V;i++){
    fanc[i]=fanc[i-1]*i%MOD;
    inv[i]=MOD-(MOD/i)*inv[MOD%i]%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}
ll COM(ll a,ll b){
  if(a<b)return 0;
  if(a<0||b<0)return 0;
  return (fanc[a]*finv[a-b]%MOD)*finv[b]%MOD;
}
int main(){
  ll N,K;
  cin>>N>>K;
  COMinit();
  N-=K;
  for(ll i=1;i<=K;i++){
		ll ans = 0;
		ans = COM(N+1,i);
		// b1 + b2 + ... + bi = k;
		ans *= COM(K-1,i-1);
		ans %= MOD;
		cout << ans << endl;
  }
}