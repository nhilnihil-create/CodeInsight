#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using p = pair<ll, ll>;
constexpr ll INF = 1LL << 62;
constexpr ll MOD = 998244353;

int main(void) {
  ll N, S;
  cin >> N >> S;
  vector<ll> A(N);
  for (auto&& a : A) {
    cin >> a;
  }

  // Tを荷物候補、UをTの中から選ばれた荷物の集合と考える。
  vector<vector<ll> > dp(N + 1, vector<ll>(S + 1, 0));
  dp[0][0] = 1;
  for (ll i = 1; i <= N; i++) {
    for (ll j = 0; j <= S; j++) {
      dp[i][j] += dp[i - 1][j] * 2; // そもそもTに選ばれるかどうかで2パターン分岐する。Tに入る or 入らないなので。
      dp[i][j] %= MOD;

      if (j + A[i - 1] > S) {
        continue;
      }

      dp[i][j + A[i - 1]] += dp[i - 1][j]; // Uに選んだら、スコアが A[i - 1] 増える。その状況に到達できるパターン数は dp[i - 1][j] 増える。
      dp[i][j + A[i - 1]] %= MOD;
    }
  }

  cout << dp[N][S] << endl;
  
  return 0;
}
