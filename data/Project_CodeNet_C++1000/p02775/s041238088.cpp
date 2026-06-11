#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string N;
  cin >> N;
  vector<vector<lint>> dp(N.size()+1, vector<lint>(2));
  dp[N.size()][1] = 1e9;
  IREP(i, N.size()) {
    dp[i][0] = dp[i+1][0] + (N[i]-'0');
    if(N[i] != 9) dp[i][0] = min(dp[i][0], dp[i+1][1] + (N[i]-'0') + 1);
    dp[i][1] = dp[i+1][1] + (10 - (N[i]-'0') - 1);
    if(N[i] != 0) dp[i][1] = min(dp[i][1], dp[i+1][0] + (10 - (N[i]-'0')));
  }
  cout << min(dp[0][0], dp[0][1]+1) << endl;
}