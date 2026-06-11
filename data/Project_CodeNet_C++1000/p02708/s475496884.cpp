#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
  ll n, k, ans = 0;
  cin >> n >> k;
  for (ll i = k; i <= n + 1; ++i) ans += n * i - i * i + i + 1, ans %= MOD;

  cout << ans << endl;
  return 0;
}
