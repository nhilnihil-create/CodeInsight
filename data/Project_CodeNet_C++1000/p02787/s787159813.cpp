#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int mx = 10e8;
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int main() {
  int H, N;
  cin >> H >> N;
  vector<int> dp(H + 5, mx);
  vector<P> A(N);
  REP(i, N) cin >> A[i].first >> A[i].second;
  dp[0] = 0;
  for (int i = 0; i < H; i++) {
    if (dp[i] == mx) continue;
    REP(j, N) {
      if (i + A[j].first <= H) {
        chmin(dp[i + A[j].first], dp[i] + A[j].second);
      } else {
        chmin(dp[H], dp[i] + A[j].second);
      }
    }
  }
  cout << dp[H] << endl;
}