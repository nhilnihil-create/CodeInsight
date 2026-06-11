#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mo=1000000007;

ll modpow(ll a, ll n, ll mod){
  ll ret = 1;
  while(n > 0){
    if(n & 1) ret = ret * a % mod;
    a =  a * a % mod;
    n >>= 1;
  }
  return ret;
}

ll MOD(ll a, ll mod){
  ll temp = a % mod;
  if(temp < 0) temp += mod;
  return temp;
}

int main(){
  ll N, K;
  cin >> N >> K;
  vector<ll> dp(K+1, 0);
  
  for(ll i=K; i>=1; i--){
    ll temp = modpow(K/i, N, mo);
    ll b = 2 * i;
    while(b<=K){
      temp = MOD(temp - dp[b] % mo, mo);
      b += i;
    }
    dp[i] = temp;
  }
  
  ll sum=0;
  for(ll i=0; i<=K; i++){
    sum = (sum + dp[i] * i % mo) % mo;
  }
  
  cout << sum << endl;
  return 0;
}