#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

static const ll MOD = 1000000007;

ll dp[2005][2005];

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> S, T;
  rep(i,N){
    int a;
    cin >> a;
    S.push_back(a);
  }
  rep(i,M){
    int a;
    cin >> a;
    T.push_back(a);
  }

  rep(i,N){
    rep(j,M){
      dp[i][j] += ((j-1>=0?dp[i][j-1]:0)-(i-1>=0&&j-1>=0?dp[i-1][j-1]:0)+MOD)%MOD;
      dp[i][j] += ((i-1>=0?dp[i-1][j]:0)-(i-1>=0&&j-1>=0?dp[i-1][j-1]:0)+MOD)%MOD;
      dp[i][j] %= MOD;
      if(S[i] == T[j]){
        dp[i][j] += 2*(i-1>=0&&j-1>=0?dp[i-1][j-1]:0) + 1;
        dp[i][j] %= MOD;
      }else{
        dp[i][j] += (i-1>=0&&j-1>=0?dp[i-1][j-1]:0);
        dp[i][j] %= MOD;
      }
    }
  }
  dp[N-1][M-1] += 1;
  dp[N-1][M-1] %= MOD;

  cout << dp[N-1][M-1] << endl;
  
  return 0;
}
