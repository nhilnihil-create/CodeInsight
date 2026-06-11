#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

int main() {

  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll& x : a) cin >> x;
  sort(a.rbegin(), a.rend());

  // 1 4 2 5 3
  // 1 4 2 5 3 6
  ll ans = 0;
  rep(i, 0, n - 1) ans += a[(i + 1) / 2];
  cout << ans << endl;

  return 0;
}