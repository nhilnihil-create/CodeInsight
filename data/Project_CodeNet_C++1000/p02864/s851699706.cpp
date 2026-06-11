#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000



int main(){
	
	int N,K;
	cin>>N>>K;
	
	vector<long long> H(N+1,0);
	for(int i=1;i<=N;i++)cin>>H[i];
	
	vector<vector<vector<long long>>> dp(N+1,vector<vector<long long>> (K+1,vector<long long>(N+1,Inf)));
	
	dp[0][0][0] = 0;
	
	for(int i=1;i<=N;i++){
		for(int j=0;j<=K;j++){
			for(int k=0;k<i;k++){
				long long h = max(0LL,H[i]-H[k]);
				dp[i][j][i] = min(dp[i][j][i],dp[i-1][j][k] + h);
				if(j==0)continue;
				dp[i][j][k] = min(dp[i][j][k],dp[i-1][j-1][k]);
			}			
		}
	}
	
	long long ans = Inf;
	for(int i=0;i<=K;i++){
		for(int j=0;j<=N;j++){
			ans = min(ans,dp.back()[i][j]);
		}
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}