
#include <bits/stdc++.h>

using namespace std;

#define int long long

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)

template <typename T> T gcd(T m, T n) { return n == 0 ? m : gcd(n, m % n); }
template <typename T> T lcm(T m, T n) { return n * m / gcd(n, m); }
template <typename T> T fact(T n) { return (n == 0 ? 1 : n * fact(n - 1)); }
template <typename T> T modpow(T a, T e, T m) { return (e == (T)0 ? 1 : ((a % m) * modpow((a % m), e - 1, m)) % m); }

constexpr int MOD = 1e9 + 7;

signed main(void) {
  int num;
  int m, d;
  cin >> m >> d;
  num = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= d; ++j) {
      int d1 = j % 10;
      int d2 = j / 10;
      if (d1 >= 2 && d2 >= 2 && d1 * d2 == i) ++num;
    }
  }
  cout << num << endl;
}