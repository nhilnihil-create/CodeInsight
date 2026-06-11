#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  vector<int> per(n);
  for (int i = 0; i < n; i++) per[i] = i;
  vector<double> dist;
  int cnt = 0;
  do {
    double d = 0;
    cnt++;
    for (int i = 0; i < n - 1; i++) {
      d += sqrt((x[per[i + 1]] - x[per[i]]) * (x[per[i + 1]] - x[per[i]]) +
                (y[per[i + 1]] - y[per[i]]) * (y[per[i + 1]] - y[per[i]]));
    }
    dist.emplace_back(d);
  } while (next_permutation(per.begin(), per.end()));
  double ans = 0;
  for (const auto& d : dist) {
    ans += d;
  }
  ans /= cnt;
  cout << fixed << setprecision(17) << ans << '\n';
  return 0;
}
