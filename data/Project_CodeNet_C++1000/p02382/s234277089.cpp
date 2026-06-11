#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  double d1 = 0.0000000, d2 = 0.0000000, d3 = 0.0000000, dul = 0.0000000;
  for(int i = 0; i < n; i++) cin >> x[i];
  for(int i = 0; i < n; i++) {
    cin >> y[i];
    double yoso = abs((double)x[i] - (double)y[i]);
    d1 += yoso;
    d2 += yoso * yoso;
    d3 += yoso * yoso * yoso;
    dul = max(dul, yoso);
  }
  cout << fixed << setprecision(7);
  cout << d1 << "\n";
  cout << sqrt(d2) << "\n";
  cout << cbrt(d3) << "\n";//
  cout << dul << "\n";
}
