#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int main() {
  int N,M;
  cin >> N >> M;
  int S[N];
  int T[M];
  for (int i = 0; i < N; i++) cin >> S[i];
  for (int i = 0; i < M; i++) cin >> T[i];
  ll DP[N+1][M+1];
  vector<ll> sum(M+1);
  
  ll ans = 1;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      DP[i][j] = 0;
    }
  }
  for (int i = 0; i <= M; i++) {
    sum[i] = 1; 
  }
  DP[0][0] = 1;

  for (int i = 1; i <= N; i++) {
    vector<ll> newsum(M+1);
    for (int j = 0; j <= M; j++) {
      newsum[j] = 0; 
    }
    for (int j = 1; j <= M; j++) {
      if (S[i-1] == T[j-1]) {
        ll r = sum[j-1];
        r %= Mod;
        DP[i][j] = r;
      }
      newsum[j] = newsum[j-1] + DP[i][j];
      newsum[j] %= Mod; 
      ans += DP[i][j];
      ans %= Mod;
    }
    for (int j = 0; j <= M; j++) {
      sum[j] += newsum[j];
      sum[j] %= Mod;
    }
  }
  cout << ans << endl;
  return 0;
}
