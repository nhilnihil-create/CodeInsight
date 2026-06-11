#include <bits/stdc++.h>
using namespace std;
#define int long long int
int dp[3005][3005];
const int N=998244353;
main() {
	int n, s;
	cin>>n>>s;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	dp[0][0]=2;
	dp[0][arr[0]]=1;
	for(int i=1; i<n; i++){
		for(int j=0; j<=3000; j++){
			dp[i][j]=(dp[i][j]+(2*dp[i-1][j]))%N;
			if(arr[i]+j>3000){
				continue;
			}
			dp[i][j+arr[i]]=(dp[i][j+arr[i]]+dp[i-1][j])%N;
		}
	}
	cout<<dp[n-1][s];
	return 0;
}