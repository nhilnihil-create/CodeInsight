#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()

ll modPow(ll a, ll n) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % MOD;
  if (n % 2 == 1) return (a * modPow(a, n - 1)) % MOD;
  ll t = modPow(a, n / 2);
  return (t * t) % MOD;
}



int main(){
  ll N,K,ans=0;
  cin >> N >> K;
  vec A(K,0);
  for(ll i=K;i>0;i--){
    A.at(i-1)=modPow(K/i,N);
    ll t=2;
    while(i*t<=K){
      A.at(i-1)+=MOD;
      A.at(i-1)-=A.at(i*t-1);
      A.at(i-1)%=MOD;
      t++;
    }
  }
  rep(i,K){
    ans+=(i+1)*A.at(i);
    ans%=MOD;
  }
  cout << ans << endl;
}