#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<long long> x(N);
  vector<long long> y(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }

  int ans = N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      int cost = N;
      long long p = x[i] - x[j];
      long long q = y[i] - y[j];
      for (int k = 0; k < N; k++) {
        for (int l = 0; l < N; l++) {
          if (x[l] - x[k] == p && y[l] - y[k] == q) {
            cost--;
          }
        }
      }
      ans = min(cost, ans);
    }
  }
  cout << ans << endl;
  return 0;
}