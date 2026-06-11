#include <bits/stdc++.h>
using namespace std;

// constexpr long MOD = 998244353;
constexpr long MOD = 1000000007;
vector<long> fact, inv;

long mpow(long a, long b) {
  long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b /= 2;
  }
  return res;
}

long com(long n, long r) {
  long x = 1, y = 1;
  for (int i = 1; i <= r; i++) {
    x = x * (n - i + 1) % MOD;
    y = y * i % MOD;
  }
  return x * mpow(y, MOD - 2) % MOD;
}

void init(int n) {
  fact.push_back(1);
  inv.push_back(1);
  for (int i = 0; i < n; i++) {
    fact.push_back(fact.at(i) * (i + 1) % MOD);
    inv.push_back(mpow(fact.at(i + 1), MOD - 2));
  }
}

long qcom(long n, long r) {
  if (n - r < 0) return 0;
  return fact.at(n) * inv.at(r) % MOD * inv.at(n - r) % MOD;
}

int main() {
  init(100000);
  int N, K;
  cin >> N >> K;
  for (int i = 1; i <= K; i++) {
    cout << qcom(K - 1, i - 1) * qcom(N - K + 1, i) % MOD << "\n";
  }
}