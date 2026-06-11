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

vi a;
vi ans;

void input() {
  a.clear();
  ans.clear();

  cin >> n;

  a.resize(n - 1);
  ans.resize(n);

  for (auto&& i : a)
    cin >> i;
}

void solve() {
  for (auto&& i : a)
    ans[i - 1]++;

  for (auto&& i : ans)
    cout << i << '\n';

  cout << '\n';
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
