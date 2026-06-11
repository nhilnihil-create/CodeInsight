#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;

int main() {
  int a, b, x;
  cin >> a >> b >> x;

  double ab = a * b;
  double s = x / static_cast<double>(a);
  double rad = 0;
  if (s >= ab / 2) {
    double num = (ab - s) * 2 / pow(a, 2);
    rad = atan(num);
  } else {
    double num = pow(b, 2) / (2 * s);
    rad = atan(num);
  }
  double ans = rad * 180 / M_PI;
  printf("%.9f\n", ans);
}
