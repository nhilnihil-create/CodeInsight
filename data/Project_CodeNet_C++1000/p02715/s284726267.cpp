#include <bits/stdc++.h>
using namespace std;

class mint {
  int value;

public:
  static const int MOD = 1000 * 1000 * 1000 + 7;
  //static const int MOD = 29;

  mint(long long x)
      : value(x % MOD) {}

  mint operator+(mint y) const {
    return mint(value + y.value);
  }

  mint operator+=(mint a) {
    return *this = *this + a;
  }

  mint operator*(mint y) const {
    return mint(long(value) * y.value);
  }

  mint operator*=(mint a) {
    return *this = *this * a;
  }

  mint operator-() const {
    return *this * mint(-1);
  }

  mint operator-(mint y) const {
    return *this + (-y);
  }

  mint operator-=(mint a) {
    return *this = *this - a;
  }

  operator int() {
    return value;
  }

  static mint pow(mint a, int n) {
    if (n <= 0) {
      return 1;
    }
    else if (n == 1) {
      return a;
    }
    mint half = pow(a, n / 2);
    return n % 2 ? half * half * a : half * half;
  }
};

int main() {
  int N, K;
  cin >> N >> K;

  vector<mint> part(K + 1, 0);

  for (int X = K; X >= 1; X--) {
    int c = floor(K / X);
    part[X] = mint::pow(c, N);
    for (int j = 2; j <= c; j++) {
      part[X] -= part[X * j];
    }
  }

  mint ans = 0;
  for (long i = 1; i <= K; i++) {
    ans += i * part[i];
  }

  cout << ans << endl;
}