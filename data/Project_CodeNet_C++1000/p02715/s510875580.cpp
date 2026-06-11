#include<bits/stdc++.h>
//#include"atcoder/all"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
//using namespace atcoder;
typedef long long ll;
const ll mod = 1000000007;
ll modpow(ll x,ll y){
  ll ans = 1;
  while(y){
    if(y&1) ans = ans*x%mod;
    x = x*x%mod;
    y >>= 1;
  }
  return ans;
}
int main(){
  ll N,K,i,j,ans = 0;scanf("%lld%lld",&N,&K);
  ll cnt[K+1] = {};
  for(i=K;i>=1;i--){
    cnt[i] = modpow(K/i,N);
    for(j=i+i;j<=K;j+=i){
      cnt[i] -= cnt[j];
      if(cnt[i] < 0) cnt[i] += mod;
    }
    ans = (ans+cnt[i]*i)%mod;
  }
  printf("%lld\n",ans);
}