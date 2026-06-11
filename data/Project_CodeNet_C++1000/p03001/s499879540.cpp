#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  ll w, h, x, y;
  cin >> w >> h >> x >> y;

  double ans = w * h / 2.0;

  int multi = 0;
  if (x * 2 == w && y * 2 == h) {
    multi = 1;
  }

  printf("%.2f0000000000 %d\n", ans, multi);
}
