#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int h1;
int s1;
int h2;
int s2;

void input() {
  cin >> h1 >> s1 >> h2 >> s2;
}

void solve() {
  bool turn = true;

  while (h1 > 0 && h2 > 0) {
    if (turn) {
      h2 -= s1;
    } else {
      h1 -= s2;
    }

    turn = !turn;
  }

  string ans = "Yes";

  if (h1 <= 0)
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
  //freopen("output.txt", "w", stdout);

  _times = 2;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}
