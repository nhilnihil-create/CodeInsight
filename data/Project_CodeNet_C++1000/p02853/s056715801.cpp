#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int x, y;
  cin >> x >> y;
  int ans = 0;
  if (x <= 3) {
    ans += 100000 * (4 - x);
  }
  if (y <= 3) {
    ans += 100000 * (4 - y);
  }
  if (x + y == 2) {
    ans += 400000;
  }

  cout << ans << endl;
  return 0;
}
