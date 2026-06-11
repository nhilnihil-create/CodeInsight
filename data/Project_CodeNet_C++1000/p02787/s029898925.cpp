#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int dp[100000 + 10];
int main() {
  int H, N;
  cin >> H >> N;
  vector<int> A(N), B(N);
  REP(i, N) cin >> A[i] >> B[i];
  REP(j, 10000 + 10) dp[j] = INF;
  dp[0] = 0;
  REP(i, N) {
    REP(j, H + 1) {
      if (j + A[i] >= H) {
        chmin(dp[H], dp[j] + B[i]);
      }
      chmin(dp[j + A[i]], dp[j] + B[i]);
    }
  }
  cout << dp[H] << endl;
}