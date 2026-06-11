#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;
LL dp[4][1000011];
LL MOD=1e9+7;

int main(){
	cin>>N;
	dp[0][0]=1;
	dp[1][0]=0;
	dp[2][0]=0;
	dp[3][0]=0;
	REP(i,N){
		dp[0][i+1]=8*dp[0][i];
		dp[1][i+1]=9*dp[1][i]+dp[0][i];
		dp[2][i+1]=9*dp[2][i]+dp[0][i];
		dp[3][i+1]=10*dp[3][i]+dp[1][i]+dp[2][i];
		dp[0][i+1]%=MOD;
		dp[1][i+1]%=MOD;
		dp[2][i+1]%=MOD;
		dp[3][i+1]%=MOD;
	}
	cout<<dp[3][N]<<endl;
	return 0;
}