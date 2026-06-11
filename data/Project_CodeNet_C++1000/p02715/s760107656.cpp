#include <iostream>
using namespace std;

const int64_t MOD = 1000000007;

int64_t pow(int64_t b, int64_t n) {
  int64_t result = 1;
  while (n != 0) {
    if (n % 2 == 1) {
      result = result * b % MOD;
    }
    n /= 2;
    b = b * b % MOD;
  }
  return result;
}

int main() {
  int64_t n, k;
  cin >> n >> k;
  int64_t dp[k + 1], result = 0;
  for (int64_t a = k; a >= 1; --a) {
    dp[a] = pow(k / a, n);
    for (int64_t b = 2 * a; b <= k; b += a) {
      dp[a] = (dp[a] - dp[b]) % MOD;
    }
    result = (result + a * dp[a]) % MOD;
  }
  cout << (result + MOD) % MOD;
  return 0;
}