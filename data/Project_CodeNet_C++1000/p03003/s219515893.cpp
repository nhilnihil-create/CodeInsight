#include<iostream>
using namespace std;
const int MOD = 1000000007;
int main(){
	int N,M,S[2000],T[2000];
	int dp[2000][2000]={0};
	cin>>N>>M;
	for(int i=0;i<N;i++)cin>>S[i];
	for(int i=0;i<M;i++)cin>>T[i];
	dp[0][0]=S[0]==T[0];
	for(int i=1;i<N;i++)dp[i][0]=dp[i-1][0]+(S[i]==T[0]);
	for(int i=1;i<M;i++)dp[0][i]=dp[0][i-1]+(S[0]==T[i]);
	for(int i=1;i<N;i++)dp[i][0]=dp[i-1][0]+(S[i]==T[0]);
	for(int i=1;i<M;i++)dp[0][i]=dp[0][i-1]+(S[0]==T[i]);
	for(int i=1;i<N;i++)for(int j=1;j<M;j++){
		if(S[i]==T[j])dp[i][j]=dp[i][j-1]+dp[i-1][j]+1;
		else dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
		dp[i][j]=(dp[i][j]%MOD+MOD)%MOD;
	}
	cout<<dp[N-1][M-1]+1;
	return 0;
}
