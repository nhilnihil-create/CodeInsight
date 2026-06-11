#include <iostream>
#define MIN(a,b) ((a>b)?(b):(a))
using namespace std;

int main(void){
	int n,m;
	int p[20];
	int dp[50001];
	cin>>n>>m;
	for(int i=0;i<m;i++)cin>>p[i];
	for(int i=0;i<=n;i++)dp[i]=9999999;
	dp[0]=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<=n;j++){
			if(j-p[i]>=0)dp[j]=MIN(dp[j-p[i]]+1,dp[j]);
			else dp[j]=dp[j];
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}