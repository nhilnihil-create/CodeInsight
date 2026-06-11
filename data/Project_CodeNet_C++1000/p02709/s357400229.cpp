#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N;
  cin >> N;
  vector<pair<ll,ll>> A(N);
  for(ll i=0; i<N; ++i) {
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  
  vector<vector<ll>> dp(N+1, vector<ll>(N+1));
  
  for(ll i=0; i<=N-1; ++i) for(ll j=0; j<=i+1; ++j){
    if(j<=i) dp[i+1][j] = max(dp[i+1][j], dp[i][j] + A[i].first * (N-1-i+j - A[i].second));
    if(j>=1) dp[i+1][j] = max(dp[i+1][j], dp[i][j-1] + A[i].first * (A[i].second - (j-1)));
  }
  
  ll ans = dp[N][0];
  for(ll i=1; i<=N; ++i) ans = max(ans, dp[N][i]);
  
  cout << ans << '\n';
  return 0;
}
