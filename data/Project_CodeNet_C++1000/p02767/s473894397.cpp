#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<int> X(N);
  rep(i, N) cin >> X[i];

  int ans = INT_MAX;
  int calc = 0;
  for (int i = 1; i <= 100; i++) {
    rep(j, N) calc += (X[j] - i) * (X[j] - i);
    ans = min(ans, calc);
    calc = 0;
  }
  cout << ans << endl;
  return 0;
}