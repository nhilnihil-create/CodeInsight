#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;

  auto sumup = [&](int64_t i) { return i * (i + 1) / 2; };

  int64_t ans = 0;
  for (int i = k; i <= n + 1; i++) {
    int64_t min = sumup(i - 1);
    int64_t max = sumup(n) - sumup(n - i);
    ans += max - min + 1;
    ans %= MOD;
  }
  ans = ans % MOD;
  cout << ans << endl;
}
