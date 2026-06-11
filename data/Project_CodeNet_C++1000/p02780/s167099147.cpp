#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> p(n);
  vector<double> e(n);
  for (int i = 0; i < n; ++i) {
    int pi;
    cin >> pi;
    p[i] = pi;
    double ei = ((double)pi + 1) / 2;
    e[i] = ei;
  }

  double ret = 0.0;
  double sum = 0.0;
  for (int i = 0; i < n; ++i) {
    if (i >= k) {
      sum -= e[i - k];
    }
    sum += e[i];
    ret = max(ret, sum);
  }

  cout << std::fixed << std::setprecision(15) << ret << endl;

  return 0;
}
