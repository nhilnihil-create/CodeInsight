#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int n;

void input() {
  cin >> n;
}

void solve() {
  int x = round(1.0l * n / 1.08);

  string ans = ":(";

  for (int i = max(1, x - 10); i < x + 10; ++i) {
    if ((int)floor(i * 1.08l) == n) {
      ans = to_string(i);

      break;
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
  //freopen("output.txt", "w", stdout);

  _times = 3;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}
