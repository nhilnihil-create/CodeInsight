#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <numeric>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int n;

void input() {
  cin >> n;
}

void solve() {
  ll ans = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k)
        ans += gcd(i, gcd(j, k));
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout.precision(16);
  cout << fixed;

  int _times = 1;

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  _times = 2;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}
