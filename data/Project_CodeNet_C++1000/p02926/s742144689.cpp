#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<vector<double>> a(n, vector<double>(3));
  for (int i = 0; i < n; i++) {
    cin >> a.at(i).at(1) >> a.at(i).at(2);
    complex<double> c1(a.at(i).at(1), a.at(i).at(2));
    a.at(i).at(0) = arg(c1);
  }
  
  sort(a.begin(), a.end());
  
  for (int i = 0; i < n; i++) a.emplace_back(a.at(i));
  
  double ans = 0;
  for (int i = 0; i < n; i++) {
    complex<double> c(0, 0);
    for (int j = 0; j < n; j++) {
      complex<double> c2(a.at(i + j).at(1), a.at(i + j).at(2));
      c += c2;
      ans = max(ans, abs(c));
    }
  }
  
  cout << fixed << setprecision(15) << ans << '\n';
}