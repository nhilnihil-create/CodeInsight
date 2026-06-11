#include <bits/stdc++.h>
using namespace std;

#define rep(i, u) for (int i = 0; i < u; i++)

using ll = long long;
using ull = unsigned long long;

int main() {
  int n;
  double d1 = 0, d2 = 0, d3 = 0, d = 0;
  int x[100] = {}, y[100] = {}, xy[100] = {};
  cin >> n;
  rep(i, n) cin >> x[i];
  rep(i, n) cin >> y[i];
  rep(i, n) xy[i] = abs(x[i] - y[i]);
  rep(i, n) d1 += xy[i];
  cout << fixed << setprecision(10) << d1 << endl;
  rep(i, n) d2 += pow(xy[i], 2);
  cout << fixed << setprecision(10) << sqrt(d2) << endl;
  rep(i, n) d3 += pow(xy[i], 3);
  cout << fixed << setprecision(10) << cbrt(d3) << endl;
  rep(i, n) if (d < xy[i]) d = xy[i];
  cout << fixed << setprecision(10) << d << endl;
  return 0;
}

