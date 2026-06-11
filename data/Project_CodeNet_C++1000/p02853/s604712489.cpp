
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
  int num = 0;
  int x, y;
  cin >> x >> y;
  if (x == 1 && y == 1) { num += 400000; }
  if (x == 1) { num += 300000; }
  if (x == 2) { num += 200000; }
  if (x == 3) { num += 100000; }
  if (y == 1) { num += 300000; }
  if (y == 2) { num += 200000; }
  if (y == 3) { num += 100000; }
  cout << num << endl;
}