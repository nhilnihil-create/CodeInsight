#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG



signed main() {
  int N; cin >> N;
  vector<pair<int,int>> A(N, pair<int,int>());
  rep(i, N) {
    int a; cin >> a;
    A[i] = make_pair(a, i);
  }
  sort(all(A));
  reverse(all(A));
  
  vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
  
  
  rep(i, N) {
    rep(j, i+2) {
      if(j == 0) dp[j][i+1-j] = dp[j][i-j] + A[i].first*abs(A[i].second-(N-1-(i-j)));
      else if(j == i+1) dp[j][i+1-j] = dp[j-1][i+1-j] + A[i].first*abs(A[i].second-j+1);
      else {
        dp[j][i+1-j] = max(dp[j-1][i+1-j] + A[i].first*abs(A[i].second-j+1),
                           dp[j][i-j] + A[i].first*abs(A[i].second-(N-1-(i-j))));
      }
    }
  }
  
  int ans = 0;
  rep(i, N+1) ans = max(ans, dp[i][N-i]);
  
  cout << ans << endl;
  
}
