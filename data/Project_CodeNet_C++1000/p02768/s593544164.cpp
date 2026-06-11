#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

const int64_t MOD = 1'000'000'007L;

int64_t dpow(int64_t x, int64_t y) {
  if (y == 0) {
    return 1;
  }
  if (y % 2 == 0) {
    return dpow(x * x % MOD, y / 2);
  } else {
    return x * dpow(x, y - 1) % MOD;
  }
}

int64_t inv(int64_t x) { return dpow(x, MOD - 2); }

int64_t comb(int64_t n, int64_t k) {
  int64_t a = 1, b = 1;
  for (int64_t i = 0; i < k; i++) {
    a *= (n - i);
    a %= MOD;
    b *= i + 1;
    b %= MOD;
  }
  return a * inv(b) % MOD;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  cout << (((dpow(2, n) - 1 + MOD) % MOD - comb(n, a) + MOD) % MOD -
           comb(n, b) + MOD) %
              MOD
       << endl;

  return 0;
}