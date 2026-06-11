#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int w, h, x, y;
  cin >> w >> h >> x >> y;
  ll area = (ll)h * (ll)w;
  double div = (double)area / 2.0;
  int method;
  if (2 * x == w && 2 * y == h) {
    method = 1;
  } else {
    method = 0;
  }

  printf("%.10lf %d\n", div, method);
}