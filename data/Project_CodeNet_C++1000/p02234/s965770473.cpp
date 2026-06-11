#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[111][111];
ll R[111],C[111];
int main(){
  int n;

  fill(dp[0],dp[110],1000000000000000000LL);

  cin >> n;
  for(int i=0;i<n;i++)
    cin >> R[i] >> C[i];

  for(int i=0;i<n;i++) dp[i][i] = 0;

  for(int k=1;k<n;k++){
    //cout << k << endl;
    for(int i=0;i<n-k;i++){
      for(int j=i;j<i+k;j++){
	///	printf("dp[%d][%d] = %lld + dp[%d][%d] = %lld + %lld * %lld * %lld\n",
	//     i,j,dp[i][j],j+1,i+k,dp[j+1][i+k],R[i],C[i+k],min(C[j],R[j+1]));
	dp[i][i+k] = min( dp[i][i+k],
			  dp[i][j]+dp[j+1][i+k] + 
			  R[i] * C[i+k] * min(C[j],R[j+1]) );
      }
      //  printf("dp[%d][%d] = %lld\n",i,i+k,dp[i][i+k]);
    }
  }

  cout << dp[0][n-1] << endl;
}