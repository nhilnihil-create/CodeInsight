#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12); 
  int n;
  double x[100], y[100], a = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> y[i];
  }
  for (int i = 0; i < n; i++) {
    a += abs(x[i] - y[i]);
  }
  cout << a << '\n';
  a = 0;
  for (int i = 0; i < n; i++) {
    a += pow(x[i] - y[i], 2);
  }
  cout << sqrt(a) << '\n';
  a = 0;
  for (int i = 0; i < n; i++) {
    a += pow(abs(x[i] - y[i]), 3);
  }
  cout << cbrt(a) << '\n';
  a = 0;
  for (int i = 0; i < n; i++) {
    a = max(a, abs(x[i] - y[i]));
  }
  cout << a << '\n';
  return 0;
}

