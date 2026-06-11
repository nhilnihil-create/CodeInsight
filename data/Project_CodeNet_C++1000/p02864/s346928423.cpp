#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<int, int>;
using PL = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, K;
  cin >> N >> K;
  vector<lint> H(N+2);
  FOR(i, 1, N+1) cin >> H[i];
  vector<vector<lint>> dp(N+2, vector<lint>(K+1, 1e18));
  dp[0][0] = 0;
  FOR(i, 1, N+2) REP(j, i) REP(k, K+1) {
    int delcnt = i - j - 1;
    if(k-delcnt >= 0) dp[i][k] = min(dp[i][k], dp[j][k-delcnt] + max(0LL, H[i]-H[j]));
  }
  cout << dp[N+1][K] << endl;
}