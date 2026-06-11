#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

double ev(int n) { return n * (n + 1) / 2.0 / n; }

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> p(n);
  rep(i, n) std::cin >> p[i];

  double sum = 0;
  rep(i, k) { sum += ev(p[i]); }
  double maxv = sum;
  for (int i = k; i < n; i++) {
    sum = sum - ev(p[i - k]) + ev(p[i]);
    maxv = max(maxv, sum);
  }

  std::cout << fixed << setprecision(10) << maxv << std::endl;
  return 0;
}
