#include <bits/stdc++.h>
typedef long long int ll;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define chmin(x, a) do { x = min(x, a); } while(0)

using namespace std;

const int M = 998244353;
int N, S;
// U ⊆T ⊆A
int a[3001];
int dp[3001][3001];

int main() {
  cin >> N >> S;
  for (int i = 1; i <= N; i++)
    cin >> a[i];
  dp[0][0] = 1;
  for (int i = 0; i < N; i++) for (int j = 0; j <= S; j++) {
    int ni = i + 1;

    // 1) a[ni] が U に含まれる
    int nj = j + a[ni];
    if (nj <= S) (dp[ni][nj] += dp[i][j]) %= M;

    // 2) a[ni] が T に含まれる
    (dp[ni][j] += dp[i][j]) %= M;

    // 3) a[ni] が U,T に含まれない
    (dp[ni][j] += dp[i][j]) %= M;
  }
  cout << dp[N][S] << endl;
  return 0;
}