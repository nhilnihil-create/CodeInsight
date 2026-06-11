#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int w, h, x, y;
  cin >> w >> h >> x >> y;
  double s = (double)w * (double)h / 2.0;
  if (x + x == w && y + y == h) {
    cout << fixed << setprecision(10) << s << " " << '1' << endl;
  } else {
    cout << fixed << setprecision(10) << s << " " << '0' << endl;
  }
  return 0;
}
