#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long double> P(N);
  for (int i = 0; i < N; i++) cin >> P.at(i);
  for (int i = 0; i < N; i++) {
    P.at(i) = (P.at(i) + 1) / 2.0;
  }
  vector<long double> R(N + 1);
  for (int i = 1; i < N + 1; i++) R.at(i) = R.at(i - 1) + P.at(i - 1);
  long double ans = 0;
  for (int i = K; i < N + 1; i++) {
    ans = max(ans, R.at(i) - R.at(i - K));
  }
  cout << fixed << setprecision(6) << ans << "\n";
}