#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

constexpr int m = 3;

vector<vi> a(m, vi(m));

int n;
vi b;

void input() {
  for (auto&& i : a) {
    for (auto&& j : i)
      cin >> j;
  }

  cin >> n;

  b.resize(n);
  for (auto&& i : b)
    cin >> i;
}

void solve() {
  sort(b.begin(), b.end());

  for (auto&& i : a) {
    for (auto&& j : i) {
      if (binary_search(b.cbegin(), b.cend(), j))
        j = 0;
    }
  }

  string ans = "No";
  int cnt = 0;

  for (int i = 0; i < m; ++i)
    cnt += a[i][i] == 0;

  if (cnt == 3)
    ans = "Yes";

  cnt = 0;

  for (int i = 0; i < m; ++i)
    cnt += a[i][m - i - 1] == 0;

  if (cnt == 3)
    ans = "Yes";

  for (auto&& i : a) {
    if (count(i.cbegin(), i.cend(), 0) == 3)
      ans = "Yes";
  }

  for (int i = 0; i < m; ++i) {
    cnt = 0;

    for (int j = 0; j < m; ++j)
      cnt += a[j][i] == 0;

    if (cnt == 3)
      ans = "Yes";
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
