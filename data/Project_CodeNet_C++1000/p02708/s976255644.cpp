#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)

/* clang-format on */
int main() {
  ll n, k;
  scanf("%lli %lli", &n, &k);
  ll ans = 0;
  ans = (-(n + 1) * (n + 2) * (2 * n + 3) / 6) % MOD+MOD +
        k * (k - 1) * (2 * k - 1) / 6 % MOD +
        ((n + 1) * ((n + 1) * (n + 2) / 2 - k * (k - 1) / 2)) % MOD + n - k + 2;
  printf("%lli\n", ans % MOD);
  return 0;
}
