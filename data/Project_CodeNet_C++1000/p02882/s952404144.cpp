#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const double PI = acos(-1);

int main() {
  double a, b, x;
  cin >> a >> b >> x;
  x /= a;
  if (x <= a * b / 2) {
    double d = x / b * 2;
    double theta = atan(b / d);
    printf("%.10lf\n", theta * 180 / PI);
  } else {
    double d = (a * b - x) / a * 2;
    double theta = atan(d / a);
    printf("%.10lf\n", theta * 180 / PI);
  }
  return 0;
}
