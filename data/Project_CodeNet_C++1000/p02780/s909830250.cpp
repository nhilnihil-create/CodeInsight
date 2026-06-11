#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];

  vector<int> e(n);
  for (int i = 0; i < n; i++) {
    e[i] = p[i] + 1;
  }

  double sum = 0;
  for (int i = 0; i < k; i++) sum += e[i];

  double ans = sum / 2.0;
  for (int i = 0; i + k < n; i++) {
    sum = sum - e[i] + e[i + k];
    double tmp = sum / 2.0;
    ans = max(ans, tmp);
  }
  printf("%.8f\n", ans);
}
