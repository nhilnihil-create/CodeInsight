#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i< (int)(b); ++i)
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
typedef long double ld;
using ll=long long;
using namespace std;
const int mod=1e9+7;
const ld pi = (acos(-1));
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  
  int n; cin >> n;
  vector<pair<ll,ll>> a(n);
  rep(i,0,n) cin >> a[i].first ,a[i].second=i;
  sort(rALL(a));
  vector<vector<ll>> dp(n+1, vector<ll>(n+1,0));
  rep(i,0,n){
    rep(j,0,n-i){
      chmax(dp[i+1][j],dp[i][j]+a[i+j].first*(a[i+j].second-i));
      chmax(dp[i][j+1],dp[i][j]+a[i+j].first*((n-1-j)-a[i+j].second));
    }
  }
  ll ans=0;
  rep(i,0,n+1) chmax(ans,dp[i][n-i]);
  cout << ans << endl; 
}