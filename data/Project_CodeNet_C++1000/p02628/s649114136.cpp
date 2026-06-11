#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> P(N);
  rep(i, N) cin >> P[i];
  sort(P.begin(), P.end());

  int ans = 0;
  rep(i, K) ans += P[i];
  cout << ans << endl;
  return 0;
}