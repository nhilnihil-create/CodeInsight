#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <set>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int n;

set<string> a;

void input() {
  a.clear();

  cin >> n;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    a.insert(s);
  }
}

void solve() {
  cout << a.size() << '\n';
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
