#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long w, h, x, y;
  cin >> w >> h >> x >> y;
  cout << fixed << setprecision(17) << (w * h) / 2. << ' ';
  if (2 * x == w && 2 * y == h) {
    cout << 1 << '\n';
  } else {
    cout << 0 << '\n';
  }
  return 0;
}
