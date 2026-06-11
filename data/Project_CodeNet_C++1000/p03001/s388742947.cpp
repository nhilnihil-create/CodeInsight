#include <bits/stdc++.h>
using namespace std;

int main() {
  long long w, h, x, y;

  cin >> w >> h >> x >> y;

  cout << fixed << setprecision(12) << (w * h / 2.0L) << ' ' << (x + x == w && y + y == h) << endl;
}