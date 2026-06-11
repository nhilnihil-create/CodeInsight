#include <bits/stdc++.h>

using namespace std;

int main(void) {
  const long long MOD = 1000000007;

  long long n, a, b;
  cin >> n >> a >> b;

  int l = 31, r = 1;
  while (l - r != 1) {
    if (n / (1 << ((l+r) / 2))) {
      r = (l+r) / 2;
    } else {
      l = (l+r) / 2;
    }
  }
  
  int logN = r+1;
  long long C[logN];
  C[0] = 2LL;
  for (int i = 0; i < logN-1; ++i) {
    C[i+1] = C[i] * C[i];
    C[i+1] %= MOD;
  }

  long long combination = 1;
  for (int i = 0; i < logN; ++i) {
    if (n & (1 << i)) {
      combination *= C[i];
      combination %= MOD;
    }
  }
  
  combination = (combination != 0) ? combination-1 : MOD-1;

  /* https://drken1215.hatenablog.com/entry/2018/06/08/210000 */
  /* 逆元テーブル */
  int K = max(a, b)+1;
  long long inv[K];
  inv[1] = 1;
  for (int i = 2; i < K; ++i){
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
  }

  long long nCa, nCb, c = 1;
  for (int i = 0; i < max(a, b); ++i) {
    c *= n-i;
    c %= MOD;
    c *= inv[i+1];
    c %= MOD;

    if (i+1 == a) nCa = c;
    if (i+1 == b) nCb = c;
  }

  long long ans = combination - (nCa + nCb) + 2*MOD;
  ans %= MOD;
  
  cout << ans << endl;
  return 0;
}