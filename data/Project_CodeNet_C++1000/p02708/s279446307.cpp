#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

constexpr ll MOD = 1000000007;

int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  for (ll i = k; i <= n + 1; ++i) {
    ll mn = i * (i - 1) / 2;
    ll mx = (n + (n - i + 1)) * i / 2;
    ans = (ans + mx - mn + 1) % MOD;
  }
  cout << ans << endl;
  return 0;
}