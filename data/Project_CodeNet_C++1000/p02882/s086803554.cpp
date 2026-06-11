#include <bits/stdc++.h>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int A, B, X;
  cin >> A >> B >> X;
  int total = A * A * B;
  double ans;
  if (X * 2 >= total) {
    // 半分以上の水
    double air = total - X;
    // A * A * A * tanθ * .5
    double tanTheta = air / (A * A * A * .5);
    ans = atan(tanTheta) * 180 / M_PI;
  } else {
    // A * B * B * tanθ * 0.5
    double tanTheta = X / (A * B * B * .5);
    ans = 90 - atan(tanTheta) * 180.0 / M_PI;
  }
  printf("%.8f\n", ans);
  return 0;
}