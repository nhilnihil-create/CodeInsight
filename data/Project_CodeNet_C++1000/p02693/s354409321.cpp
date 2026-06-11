#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int k;
int a;
int b;

void input() {
  cin >> k >> a >> b;
}

void solve() {
  while (a <= b) {
    if (a % k == 0) {
      cout << "OK\n";

      return;
    }

    ++a;
  }

  cout << "NG\n";
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
