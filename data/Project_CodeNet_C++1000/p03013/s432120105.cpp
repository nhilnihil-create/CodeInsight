#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> dp(100110);
  unordered_map<int, int> dest{};
  vector<ll> a(M);
  REP(i, M) {
    cin >> a[i];
    dest[a[i]]++;
  }
  REP(i, dp.size()) dp[i] = 0;
  dp[0] = 1;
  for (int i = 0; i < N; i++) {
    if (dest[i] != 0) continue;
    if (dest[i + 1] == 0) {
      dp[i + 1] += dp[i];
      dp[i + 1] %= MOD;
    }
    if (dest[i + 2] == 0) {
      dp[i + 2] += dp[i];
      dp[i + 2] %= MOD;
    }
  }
  cout << dp[N] << endl;
}