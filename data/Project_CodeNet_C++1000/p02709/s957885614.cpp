#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  vector<pair<ll,ll>> a(n);
  rep(i,n) {
    int t;
    cin >> t;
    a[i]= {t,i};
  }
  sort(a.rbegin(),a.rend());

  ll dp[n+1][n+1];
  rep(i,n+1)rep(j,n+1)dp[i][j] = 0;

  rep1(i,n){
    ll val = a[i-1].first;
    ll pre_pos = a[i-1].second;
    for(int j=0;j<=i;j++){
      if(j-1>=0) dp[i][j] = dp[i-1][j-1] + abs(j-1 - pre_pos)*val;
      if(i-1>=j) dp[i][j] = max(dp[i][j],dp[i-1][j] + abs(n - (i-1-j) -1 - pre_pos)*val);
      // cout << i << " " << j <<" "<< dp[i][j] << endl;
    }
  }
  ll ans =0;
  rep(i,n+1){
    ans = max(ans, dp[n][i]);
  }
  cout << ans << endl;


  return 0;
    

}
