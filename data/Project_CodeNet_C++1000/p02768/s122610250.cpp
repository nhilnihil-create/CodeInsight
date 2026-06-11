#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

constexpr int MOD = 1000000007;

class mint {
  int n;

 public:
  mint(int n_ = 0) : n(n_) {}
  explicit operator int() { return n; }
  friend mint operator-(mint a) { return -a.n + MOD * (a.n != 0); }
  friend mint operator+(mint a, mint b) {
    int x = a.n + b.n;
    return x - (x >= MOD) * MOD;
  }
  friend mint operator-(mint a, mint b) {
    int x = a.n - b.n;
    return x + (x < 0) * MOD;
  }
  friend mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
  friend mint &operator+=(mint &a, mint b) { return a = a + b; }
  friend mint &operator-=(mint &a, mint b) { return a = a - b; }
  friend mint &operator*=(mint &a, mint b) { return a = a * b; }
  friend bool operator==(mint a, mint b) { return a.n == b.n; }
  friend bool operator!=(mint a, mint b) { return a.n != b.n; }
  friend istream &operator>>(istream &i, mint &a) { return i >> a.n; }
  friend ostream &operator<<(ostream &o, mint a) { return o << a.n; }
};

mint modpow(mint a, long long b) {
  mint res = 1;
  while (b > 0) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}

mint modinv(mint n) {
  int a = (int)n, b = MOD;
  int s = 1, t = 0;
  while (b != 0) {
    int q = a / b;
    a -= q * b;
    s -= q * t;
    swap(a, b);
    swap(s, t);
  }
  return s >= 0 ? s : s + MOD;
}

mint C(int n, int r) {
  mint res = 1;
  rep(i, r) {
    res *= n - i;
    res *= modinv(i + 1);
  }
  return res;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  mint ans = modpow(2, n) - 1;
  ans -= C(n, a);
  ans -= C(n, b);
  cout << ans << endl;
}
