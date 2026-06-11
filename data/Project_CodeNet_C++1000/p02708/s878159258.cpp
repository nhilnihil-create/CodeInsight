#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  for (long long i = k; i <= n + 1; i++) {
    ans += i * (2 * n - i + 1) / 2;
    ans -= i * (i - 1) / 2;
    ans += 1;
    ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}