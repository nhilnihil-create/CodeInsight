#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int mod = 1000000007;
const ll INF = 1001001001;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[3005][3005];

int main(){
  int n,t;
  cin >> n >> t;
  vector<P> a(n);
  rep(i,n) cin >> a[i].first >> a[i].second;
  sort(a.begin(),a.end());
  int ans = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<t;j++){
      if(j>=a[i].first){
        chmax(dp[i+1][j],dp[i][j-a[i].first]+a[i].second);
      }
      chmax(dp[i+1][j],dp[i][j]);
    }
    ans = max(ans,dp[i][t-1]+a[i].second);
  }
  cout << ans << endl;
}