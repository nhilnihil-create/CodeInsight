#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MOD = 1000000007;

long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

long long comb(long long n, long long a, long long mod) {
  if (a == 0)
    return 1;

  long long res = 1;
  for (auto i = 1; i <= a; i++) {
    res = (res * (n - a + i)) % mod;
  }
  long long d = 1;
  for (auto i = 1; i <= a; i++) {
    d = (d * i) % mod;
  }

  res = (res * modpow(d, mod - 2, mod)) % mod;
  return res;
}

long long int n, a, b;

int main() {
  cin >> n >> a >> b;

  int res = modpow(2, n, MOD) - 1;
  res = (res + MOD - comb(n, b, MOD)) % MOD;
  res = (res + MOD - comb(n, a, MOD)) % MOD;

  cout << res << endl;

  return 0;
}