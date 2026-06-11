#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 210000;
const ll MOD = 1000000007;

ll RS(ll N, ll P, ll M) {
  if(P == 0) return 1;
  if(P%2 == 0) {
      ll t = RS(N, P/2, M);
      return t*t % M;
  }
  return N * RS(N, P-1, M);
}

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> inv(MAX,1), finv(MAX,1);
  for (int i = 2; i < MAX; i++) {
    inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
  //a!の逆元はfinv[a] COM(n,a) = A*finv[a] 
  ll A, B;
  ll p = 1;
  for (ll i = 0; i < b; i++) {
    p = p * (n-i) % MOD;
    if (i == a-1) A = p;
  }
  B = p;
  ll Q = A * finv[a] % MOD + B * finv[b] % MOD;
  ll k = RS(2,n,MOD)-1-Q%MOD;
  if (k >= MOD) k -= MOD;
  if (k < 0) k += MOD;
  cout << k << endl;
}