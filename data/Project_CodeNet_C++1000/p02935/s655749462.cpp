#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<double> v(n);
  for (auto&& e : v) {
    cin >> e;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n - 1; i++) {
    v[i + 1] = (v[i] + v[i + 1]) / 2.;
  }
  cout << fixed << setprecision(10) << v[n - 1] << '\n';
  return 0;
}
