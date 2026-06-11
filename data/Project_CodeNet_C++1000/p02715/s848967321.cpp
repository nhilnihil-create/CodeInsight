#include <bits/stdc++.h>
using namespace std;

constexpr long MOD = 1000000007;

long mpow(long a, long b) {
  long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

int main() {
  long N, K;
  cin >> N >> K;
  vector<long> V(K + 1);
  for (long i = 1; i <= K; i++) {
    long tmp = K / i;
    if (tmp == 1) {
      V.at(i) = 1;
      continue;
    }
    V.at(i) = mpow(tmp, N);
  }
  for (long i = K; i >= 1; i--) {
    for (long j = i + i; j <= K; j += i) {
      V.at(i) -= V.at(j);
    }
  }
  long ans = 0;
  for (long i = 1; i <= K; i++) {
    ans += V.at(i) * i % MOD;
    ans %= MOD;
  }
  cout << ans << "\n";
}