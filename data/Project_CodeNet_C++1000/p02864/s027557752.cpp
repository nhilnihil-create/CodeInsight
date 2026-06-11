#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

const int n_max = 310;
ll dp[n_max][n_max];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  cin >> n >> k;

  vector<int> h(n+1);
  h[0]=0;
  rep(i,n){
    cin >> h[i+1];
  }
  rep(i,n+1)rep(j,n+1) dp[i][j] = LLONG_MAX/10;
  dp[0][0]=0;
  rep1(i,n){
    rep1(j,min(n-k,i)){
      rep(l,i){
	dp[i][j] = min(dp[i][j],dp[l][j-1] + max(0,h[i]-h[l]));
      }
      //      cout << "i j dp "<< i << " " << j << " " << dp[i][j] << endl;
    }
  }
  ll ans = LLONG_MAX;
  rep(i,n+1){
    ans = min(ans, dp[i][n-k]);
  }
  cout << ans << endl;
  
  //cout << endl << endl;
  //cout << static_cast<double>(clock()) / CLOCKS_PER_SEC << "s"<<endl;
  return 0;
    

}
