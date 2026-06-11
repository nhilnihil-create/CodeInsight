#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()


int main(){
  int N, M; cin >> N >> M;
  int MOD = 1000000007;
  int S[N];
  int T[M];
  int dp[N+1][M+1] = {};
  rep(i, N){
    cin >> S[i];
    dp[i+1][0] = 1;
  }
  rep(i, M){
    cin >> T[i];
    dp[0][i+1] = 1;
  }
  dp[0][0] = 1;
  rep (i, N){
    rep(j, M){
      dp[i+1][j+1] += (dp[i+1][j] + dp[i][j+1])%MOD;
      dp[i+1][j+1] -= dp[i][j];
      dp[i+1][j+1] %= MOD;
      if (S[i] == T[j]){
        dp[i+1][j+1] += dp[i][j];
      }
      dp[i+1][j+1] %= MOD;
    }
  }
  if (dp[N][M] < 0){
    dp[N][M] += MOD;
  }
  cout << dp[N][M] << endl;
}
  