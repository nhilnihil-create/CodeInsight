#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC147 D - Xor Sum 4
// 2020.06.19

ll MOD = 1e9+7;
ll fastpow(ll a, ll n){  // a^n mod MOD
  if(n==0) return 1;
  if(n%2==0){
    ll t = fastpow(a, n/2) % MOD;
    return t*t % MOD;
  }
  return a * fastpow(a, n-1) % MOD;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N; cin >> N;
  vector<ll> A(N);
  REP(i, N){
    cin >> A[i];
  }
  vector<ll> B(60, 0);
  REP(i, N){
    REP(j, 60){
      if((A[i] >> j) & 1) B[j]++; 
    }
  }
  
  vector<ll> P(60);
  REP(i, 60){
    P[i] = fastpow(2, i)%MOD;
  }

  ll ans = 0;
  REP(i, N-1){
    REP(j, 60){
      if((A[i] >> j) & 1){
        B[j]--;
        ans = (ans + P[j]*(N-1-i-B[j]))%MOD;
      }else{
        ans = (ans + P[j]*B[j])%MOD;
      }
    }
  }
  cout << ans << endl;
}