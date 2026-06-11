#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

double n, a, b, c;

int main() {
  cin >> n;
  vector<double> x(n);
  vector<double> y(n);
  rep (i, n) {
    cin >> x[i] >> y[i];
  }
  a = 0; b = 0; c = 0;
  rep (i, n) {
    for (int j = i+1; j < n; ++j) {
      a = (x[i] - x[j]) * (x[i] - x[j]);
      b = (y[i] - y[j]) * (y[i] - y[j]);
      c += pow(a + b, 0.5);
    }
  }
  cout << fixed << setprecision(10) << c * 2 / n << endl;
  return 0;
}
