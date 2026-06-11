#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
#define mod 1000000007;
using namespace std;
typedef long long ll;

ll modpow(ll a, ll n){

ll ret = 1;
  while(n){
    if(n & 1) ret=ret*a % mod;
    a = a*a % mod;

    n >>= 1;
  }

  return ret;
}

int main(){
  ll N,K;
  cin>>N>>K;

  ll d[K+1];

  for(ll i=1;i<=K;i++){
    d[i] = modpow(K/i,N);
  }

  for(ll i= K; i>=1; i--){
    for(ll j = 2*i; j <= K; j+=i){
      d[i] -= d[j];
    }
  }

  ll ans=0;
  for(ll i=1;i<=K;i++){
    ans += (d[i]*i )% mod;
  }

  cout<<ans % mod;
}
