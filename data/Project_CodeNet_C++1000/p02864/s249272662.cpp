#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

int main(){
  int n, k; cin >> n >> k; ll h[n+2]; h[n]=0;
  for(int i=1; i<=n; i++) cin >> h[i]; h[0]=0;
  
  ll dp[k+1][n+2][n+2], mn=INF; fill(dp[0][0], dp[k+1][0], INF);
  dp[0][0][1] = 0;
  for(int i=0; i<=k; i++) {
    for(int j=0; j<=n+1; j++) {
      for(int m=0; m<=n+1; m++) {
        if (i!=0 && m!=0 && dp[i-1][j][m-1]!=INF) {
          //dp[i+1][j][m+1] = min(dp[i+1][j][m+1], dp[i][j][m]);
          ll df_new = max(0LL, h[j] - h[m]);
          ll df_old = max(0LL, h[j] - h[m-1]);
          dp[i][j][m] = min(dp[i][j][m], dp[i-1][j][m-1]-df_old+df_new);
        }
        //dp[i][m][m+1] = min(dp[i][m][m+1], dp[i][j][m] + df);
        if (j!=0 && m!=0) {
          ll df = max(0LL, h[m-1] - h[m]);
          dp[i][m-1][m] = min(dp[i][m-1][m], dp[i][j-1][m-1]+df);
        }
        //if (m==n+1) mn = min(dp[i][j][m], mn);
        //if (dp[i][j][m] != INF)
          //cout << i << " " << j << " " << m << " " << dp[i][j][m] << endl;
      }
    }
  }
  for(int i=0; i<=k; i++) {
    for(int j=0; j<=n+1; j++) {
      for(int m=0; m<=n+1; m++) {
        //cout << dp[i][j][m] << " ";
      } //cout << endl;
    } //cout << endl;
  }
  
  for(int i=0; i<=k; i++) {
    for(int j=0; j<=n+1; j++) {
      mn = min(mn, dp[i][j][n+1]);
      //cout << dp[i][j][n+1] << " ";
    }//cout << endl;
  }
  
  cout << mn << endl;
}
