#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

double expected_value(int n) {
  return (double)((1 + n) * n / 2) / (double)n;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<double> ps(n);
  int p;
  rep(i, n) {
    cin >> p;
    ps[i] = expected_value(p);
  }
  double sum = 0;
  for (int i = 0; i < k; i++) {
    sum += ps[i];
  }
  double mm = sum;
  for (int i = 1; i <= n - k; i++) {
    sum -= ps[i - 1];
    sum += ps[i + k - 1];
    mm = max(sum, mm);
  }
  printf("%.6f\n", mm);
  return 0;
}