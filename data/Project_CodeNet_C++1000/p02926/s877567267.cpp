#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<complex<double>> in(n);
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    in[i].real(x);
    in[i].imag(y);
  }
  sort(in.begin(), in.end(), [] (complex<double> a, complex<double> b) {return arg(a) < arg(b);});
  double ans = 0;
  for (int i = 0; i < n; i++) {
    for (int len = 1; len <= n; len++) {
      double x = 0, y = 0;
      for (int j = 0; j < len; j++) {
        x += in[(i + j) % n].real();
        y += in[(i + j) % n].imag();
      }
      ans = max(ans, x * x + y * y);
    }
  }
  cout << setprecision(20) << fixed << sqrt(ans) << endl;
  return 0;
}