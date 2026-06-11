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
int m;

vi a;

void input() {
  cin >> n >> m;

  a.resize(n);
  for (auto&& i : a)
    cin >> i;
}

void solve() {
  int sum = 0;

  for (auto&& i : a)
    sum += i;

  int need = (sum + 4 * m - 1) / (4 * m);
  int cnt = 0;

  for (auto&& i : a)
    cnt += i >= need;

  string ans = "Yes";

  if (cnt < m)
    ans = "No";

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

  _times = 3;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}
