#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1000000007;

main() {
	int n, m;
	cin>>n>>m;
	int a[n];
	int b[m];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<m; i++){
		cin>>b[i];
	}
	int dp[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i==0 && j==0){
				if(a[0]==b[0]){
					dp[0][0]=2;
					continue;
				}
				else{
					dp[0][0]=1;
					continue;
				}
			}
			if(i==0){
				dp[i][j]=dp[i][j-1]+(a[0]==b[j]);
				dp[i][j]=dp[i][j]%N;
				continue;
			}
			if(j==0){
				dp[i][j]=dp[i-1][j]+(b[0]==a[i]);
				dp[i][j]=dp[i][j]%N;
				continue;
			}
			if(a[i]==b[j]){
				dp[i][j]=(dp[i-1][j]+dp[i][j-1])%N;
			}
			else{
				dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+N)%N;
			}
		}
	}
	cout<<dp[n-1][m-1];
	return 0;
}