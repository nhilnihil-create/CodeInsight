#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)

/* clang-format on */
int main() {
  int_fast64_t n, k;
  scanf("%zu %zu", &n, &k);
  int_fast64_t a = (n + 1) * (n + 2) / 2;
  int_fast64_t b = k * (k - 1) / 2;
  int_fast64_t ans = (-a * (2 * n + 3) / 3) % MOD + MOD +
                     b * (2 * k - 1) / 3 % MOD + ((n + 1) * (a - b)) % MOD + n -
                     k + 2;
  printf("%zu\n", ans % MOD);
  return 0;
}
