#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
//constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;

constexpr int MAXI = 1000006;
int dp[MAXI][2];

int main(){
  string S;
  cin >> S;
  int N = S.size();
  dp[0][1] = 1;
  REP(i, N){
    int x = S[i] - '0';
    dp[i+1][0] = min(dp[i][0]+x, dp[i][1]+10-x);
    dp[i+1][1] = min(dp[i][0]+x+1, dp[i][1]+10-x-1);
  }
  cout << dp[N][0] << endl;
  return 0;
}
