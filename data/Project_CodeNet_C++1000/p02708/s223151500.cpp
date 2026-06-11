#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  for (long long i = k; i <= n + 1; ++i) {
    ans += i * (n - i + 1) + 1;
    ans %= MOD;
  }
  cout << ans << endl;
}
