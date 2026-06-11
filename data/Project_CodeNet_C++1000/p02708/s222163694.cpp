#include <bits/stdc++.h>
using namespace std;

long aps(long a, long d, long n) {
  return n * (2 * a + (n - 1) * d) / 2;
}

int main() {
  long N, K, MOD = 1e9+7;
  cin >> N >> K;
  long ans = 0;
  for (long k = K; k <= N + 1; k++) {
    long mi = aps(0, 1, k);
    long mx = aps(N - k + 1, 1, k);
    ans += mx - mi + 1;
    ans %= MOD;
  }
  cout << ans << "\n";
}