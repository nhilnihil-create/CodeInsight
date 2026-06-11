#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

ll MOD = 1e9+7;
ll fastpow(ll a, ll n){  // a^n mod MOD
  if(n==0) return 1;
  if(n%2==0){
    ll t = fastpow(a, n/2);
    return t*t % MOD;
  }
  return a * fastpow(a, n-1) % MOD;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, K; cin >> N >> K;
  vector<ll> A(K+1, 0);
  for(ll i = K; i > 0; i--){
    A[i] = fastpow(K/i, N) % MOD;
    ll cnt = 2, tmp = cnt * i;
    while(tmp <= K){
      A[i] -= A[tmp];
      if(A[i] < 0) A[i] += MOD;
      cnt++;
      tmp = cnt * i;
    }
  }
  ll ans = 0;
  for(ll i = 1; i <= K; i++){
    ans = (ans + i*A[i]) % MOD;
  }
  cout << ans << endl;
}