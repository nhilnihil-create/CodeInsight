#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

const Int MOD = 1000000007;

Int modpow(Int a, Int n) {
    Int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}


int main(){ 
  Int N, K;
  cin >> N >> K;

  vector<Int> cds(K+1,0), gcds(K+1,0);

  rep1(i,K) {
    Int q = K / i;
    cds[i] = modpow(q,N);
  }

  rep(i,K) {
    Int temp = cds[K-i];
    for (Int j = 2; j * (K-i) <= K; j++) {
      temp = (temp + MOD - gcds[j * (K-i)]) % MOD;
    }
    gcds[K-i] = temp;
  }

  Int ans = 0;

  rep1(i,K) {
    ans = (ans + (i * gcds[i] % MOD)) % MOD;
  }

  cout << ans << endl;

}