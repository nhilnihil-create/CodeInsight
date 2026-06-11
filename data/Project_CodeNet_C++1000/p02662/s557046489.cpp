#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,s;
long long a[3005];
long long dp[3005][3005];
int main(){
	cin>>n>>s;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	dp[0][0]=1;
	for(int i=0;i<n;++i){
		for(int j=0;j<=s;++j){
			dp[i+1][j]+=2*dp[i][j];
			dp[i+1][j]%=mod;
			if(j+a[i]<=s){
				dp[i+1][j+a[i]]+=dp[i][j];
				dp[i+1][j+a[i]]%=mod;
			}
		}
	}
	cout<<dp[n][s]<<'\n';
	return 0;
}