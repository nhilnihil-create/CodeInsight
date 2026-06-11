#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  sort(a.rbegin(), a.rend());

  ll ans = 0;
  rep(i, 0, (n + 1) / 2) ans += a[i];
  ans *= 2;
  ans -= a[0];
  if (n % 2 == 1) ans -= a[n / 2];

  cout << ans << endl;
  return 0;
}