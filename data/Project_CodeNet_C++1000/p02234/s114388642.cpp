#include <bits/stdc++.h>
using namespace std;

struct Mat{
	  int r,l;
};

int main(){

	  int n; cin >> n;
	  vector<Mat> Mats(n);
	  for(int i=0; i<n; i++)
			cin >> Mats[i].r >> Mats[i].l;

	  int dp[n][n] = {};
	  for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				  if(i==j) dp[i][j] = 0;
				  else dp[i][j] = INT_MAX;

	  for(int k=1; k<n; k++){
			for(int i=0; i+k<n; i++){
				  for(int j=i; j<i+k; j++){
						int num_prod = Mats[i].r * Mats[j+1].r * Mats[i+k].l;
						dp[i][i+k] = min(dp[i][i+k], dp[i][j] + dp[j+1][i+k] + num_prod);
				  }
			}
	  }
	  
	  cout << dp[0][n-1] << endl;
	  
			
}