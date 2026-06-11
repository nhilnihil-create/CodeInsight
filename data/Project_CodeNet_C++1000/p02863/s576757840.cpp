#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

int dp[3030][3030];

signed main(){
  int n,t;
  cin >> n >> t;
  vector<P> A(n);
  rep(i,0,n) cin >> A[i].first >> A[i].second;
  sort(A.begin(),A.end());
  rep(i,1,n+1){
    rep(j,0,t+1){
      if(j >= A[i-1].first) dp[i][j] = max(dp[i-1][j],dp[i-1][j - A[i-1].first] + A[i-1].second);
      else dp[i][j] = dp[i-1][j];
    }
  }
  int ans = 0;
  // rep(i,0,n+1){
    // rep(j,0,t){
      // cout << dp[i][j] << ' ';
    // }
    // cout << endl;
  // }
  rep(i,1,n+1){
    ans = max(ans,dp[i-1][t-1] + A[i-1].second);
  }
  cout << ans << endl;
}