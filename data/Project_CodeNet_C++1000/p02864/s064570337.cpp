#include <bits/stdc++.h>
using namespace std;

#define INFLL 9999999999999999LL

int N,K;
vector<long long> H;
long long dp[333][333];

int main(){
	cin >> N >> K;
	H.push_back(0);
	for(int i=0;i<N;i++){
		long long h;
		cin >> h;
		H.push_back(h);
	}
	
	for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)dp[i][j]=INFLL;
	dp[0][0]=0;
	
	for(int i=1;i<=N;i++)for(int j=1;j<=i;j++){
		for(int k=0;k<i;k++){
			dp[i][j]=min(dp[i][j],dp[k][j-1]+max(0LL,H[i]-H[k]));
		}
	}
	
	long long ans=INFLL;
	for(int i=N-K;i<=N;i++)ans=min(ans,dp[i][N-K]);
	
	/*for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++)cout << dp[i][j] << " ";
		cout << endl;
	}*/
	
	cout << ans << endl;
	return 0;
}