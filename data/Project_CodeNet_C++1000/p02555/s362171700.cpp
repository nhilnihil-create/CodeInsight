#include <bits/stdc++.h>

using namespace std; 
 
#define int long long
#define M 1000000007
 
signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
	int n;
	cin >> n;
	int dp[3001]={0};
	dp[3]=1;
	dp[4]=1;
	dp[5]=1;
	for(int i=6;i<=n;i++){
		dp[i]=1;
		for(int j=3;j<=i;j++){
			if(i-j>=3){
				dp[i]=(dp[i]+dp[i-j])%M;
			}
		}
	}
	cout << dp[n] << endl;
}
