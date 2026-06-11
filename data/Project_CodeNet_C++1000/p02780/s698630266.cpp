#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  vector<int> sum(n);
  for (int i = 0; i < k; i++) {
    sum[0] += p[i];
  }
  int smax = sum[0];
  for (int i = 0; i < n - k; i++) {
    sum[i + 1] = sum[i] - p[i] + p[i + k];
    smax = max(smax, sum[i + 1]);
  }
  cout << fixed << setprecision(15);
  cout << (double)(smax + k) / 2. << '\n';
  return 0;
}