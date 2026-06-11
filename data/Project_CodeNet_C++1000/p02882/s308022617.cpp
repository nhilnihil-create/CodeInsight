#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  double a, b, x;
  cin >> a >> b >> x;
  double theta;
  if (x >= 0.5 * a * a * b) {
    theta = atan(2 * (b / a - x / a / a / a));
  } else {
    theta = atan(a * b * b / 2 / x);
  }
  theta *= 180 / M_PI;
  printf("%.7f\n", theta);
  return 0;
}