#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 10;
const ll MOD = 1000000007;
int dp[100000 + 100] = {INF};
int main() {
  ll N, M;
  cin >> N >> M;
  unordered_map<int, int> up;
  REP(i, M) {
    int a;
    cin >> a;
    up[a]++;
  }
  dp[0] = 1;
  REP(i, N) {
    if (up[i + 1] == 0) {
      dp[i + 1] += dp[i];
      dp[i + 1] %= MOD;
    }
    if (up[i + 2] == 0) {
      dp[i + 2] += dp[i];
      dp[i + 2] %= MOD;
    }
  }
  if (dp[N] == INF) {
    cout << 0 << endl;
    return 0;
  }
  cout << dp[N] << endl;
}