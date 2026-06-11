#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  double a, b, x;
  cin >> a >> b >> x;
  
  double ans;
  if (x <= a * a * b / 2.0) {
    ans = atan(a * b * b / 2.0 / x);
  } else {
    ans = atan(2.0 * b / a - 2 * x / (a * a * a));
  }

  ans *= 180.0 / M_PI;
  printf("%.10f", ans);
  return 0;
}