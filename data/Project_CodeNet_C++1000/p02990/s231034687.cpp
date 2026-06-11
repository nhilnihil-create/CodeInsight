#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MAX = 510000;
const int mod = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = mod - inv[mod%i] * (mod / i) % mod;
    finv[i] = finv[i - 1] * inv[i] % mod;
  }
}

ll com(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
  COMinit();
  int n,k;
  cin >> n >> k;
  rep(i,1,k+1) {
    ll ans = com(n-k+1,i) * com(k-1,i-1) % mod;
    cout << ans << endl;
  }
  return 0;
}