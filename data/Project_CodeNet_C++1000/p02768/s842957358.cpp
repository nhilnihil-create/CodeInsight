#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using P = pair<long long, long long>;

const long long MOD = 1000000007;
long long finv[200001], inv[200001];

void COMinit() {
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i <= 200001; i++){
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long modpow(long long a, long long n) {
  long long res = 1;
  while(n > 0) {
    if(n & 1) res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return res;
}

int main() {
  COMinit();
  long long n, a, b;
  cin >> n >> a >> b;
  long long func[200001];
  long long ans = modpow(2, n) - 1;
  long long M = max(a, b);
  func[0] = 1;
  rep(i, M) {
    func[i+1] = func[i] * (n-i) % MOD;
  }

  ans -= func[a] * finv[a] % MOD;
  if(ans < 0) ans += MOD;

  ans -= func[b] * finv[b] % MOD;
  if(ans < 0) ans += MOD;

  cout << ans << endl;
  return 0;
}