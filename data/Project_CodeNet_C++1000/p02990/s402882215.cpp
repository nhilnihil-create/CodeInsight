#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

const ll MAX = 5123456;
const ll MOD = 1e9 + 7;
vector<ll> fac(MAX);
vector<ll> finv(MAX);
vector<ll> inv(MAX);

// COMinit()を忘れないように！
void COMinit(){
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(ll i = 2; i < MAX; i++){
    fac[i] = fac[i-1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}

ll nCr(ll n, ll r){
  if(n < r) return 0;
  if(n < 0 || r < 0) return 0;
  return fac[n] * (finv[r] * finv[n-r] % MOD) % MOD;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K; cin >> N >> K;
  COMinit();
  for(int i = 1; i <= K; i++){
    cout << nCr(N-K+1, i)*nCr(K-1, i-1)%MOD << endl;
  }
}