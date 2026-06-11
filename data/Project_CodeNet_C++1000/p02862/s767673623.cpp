// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

class combination {
 public:
  static constexpr int64 divide_by = (int64)1e9 + 7;
  combination(int64 MAX) : fac(MAX), finv(MAX), inv(MAX) {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
      fac[i] = fac[i - 1] * i % divide_by;
      inv[i] = divide_by - inv[divide_by % i] * (divide_by / i) % divide_by;
      finv[i] = finv[i - 1] * inv[i] % divide_by;
    }
  }

  int64 get_comb(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % divide_by) % divide_by;
  }

 private:
  vector<int64> fac, finv, inv;
};

int main() {
  int X, Y;
  cin >> X >> Y;
  int64 divide_by = 1e9 + 7;
  int64 ans = 0;
  int one_in_X = Y / 2;
  combination comb(max(X, Y) + 1);
  for (int i = one_in_X; i >= 0; i--) {
    if ((X - i) % 2 != 0) continue;
    int two_in_X = (X - i) / 2;
    if (i * 2 + two_in_X * 1 != Y) continue;
    ans += comb.get_comb(i + two_in_X, i);
    ans %= divide_by;
  }
  cout << ans << endl;
  return 0;
}
