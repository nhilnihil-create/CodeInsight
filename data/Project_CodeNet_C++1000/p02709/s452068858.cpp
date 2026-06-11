#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
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
  int N;
  cin >> N;
  vector<pair<lint, lint>> A(N);
  REP(i, N) {
    lint a;
    cin >> a;
    A[i] = make_pair(a, i);
  }
  sort(A.begin(), A.end(), [](auto const &a, auto const &b) { return a.first > b.first;});
  vector<vector<lint>> dp(N+1, vector<lint>(N+1));
  REP(i, N) {
    REP(j, i+1) {
      if(dp[i][j] + A[i].first*abs(A[i].second - j) > dp[i+1][j+1]) {
        dp[i+1][j+1] = dp[i][j] + A[i].first*abs(A[i].second - j);
      }
      if(dp[i][j] + A[i].first*abs(A[i].second - (N-1-(i-j))) > dp[i+1][j]) {
        dp[i+1][j] = dp[i][j] + A[i].first*abs(A[i].second - (N-1-(i-j)));
      }
    }
  }
  lint ans = 0;
  REP(i, N+1) {
    if(dp[N][i] > ans) ans = dp[N][i];
  }
  cout << ans << endl;
}