#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  double S = 0;
  cin >> n;
  vector<double> v(n);
  for(int i = 0;i < n;i++) {
    cin >> v[i];
    v[i] = 1 / v[i];
    S += v[i];
  }
  cout << fixed << setprecision(9) << 1 / S << endl;
}