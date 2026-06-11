#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int MAX = 510000;

vector<long> fact(MAX), finv(MAX), inve(MAX);

void init() {
  fact.at(0) = fact.at(1) = 1;
  finv.at(0) = finv.at(1) = 1;
  inve.at(1) = 1;
  for (int i = 2; i < MAX; i++) {
    fact.at(i) = fact.at(i - 1) * i % MOD;
    inve.at(i) = MOD - inve.at(MOD % i) * (MOD / i) % MOD;
    finv.at(i) = finv.at(i - 1) * inve.at(i) % MOD;
  }
}

long com(long n, long r) {
  if (n < r || n < 0 || r < 0) return 0;
  return fact.at(n) * (finv.at(r) * finv.at(n - r) % MOD) % MOD;
}

long mpow(long a, long b) {
  long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

long com2(long n, long r) {
  if (n < r || n < 0 || r < 0) return 0;
  long x = 1, y = 1;
  for (int i = 1; i <= r; i++) {
    x = x * (n - i + 1) % MOD;
    y = y * i % MOD;
  }
  return x * mpow(y, MOD - 2) % MOD;
}

long inv(long a) {
  long b = MOD, u = 1, v = 0;
  while (b) {
    long t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= MOD; 
  if (u < 0) u += MOD;
  return u;
}

int main() {
  ios::sync_with_stdio(false);
  init();
  int X, Y;
  cin >> X >> Y;
  if ((X + Y) % 3) return cout << 0 << "\n", 0;
  cout << com2((X + Y) / 3, Y - (X + Y) / 3) << "\n";
}