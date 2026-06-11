#include<bits/stdc++.h>
using namespace std;
int dp[41][41];
int main(void)
{
	int n,i,j,k,a,b,x,y;
	while(1) {
		cin>>a>>b;
		if(!a&&!b) break;
		cin>>n;
		for(i=0;i<b;i++) {
			for(j=0;j<a;j++) {
				dp[i][j]=0;
			}
		}
		for(i=0;i<n;i++) cin>>x>>y,x--,y--,dp[y][x]=-1;
		dp[0][0]=1;
		for(i=0;i<b;i++) {
			for(j=0;j<a;j++) {
				if(dp[i][j]!=0&&dp[i][j]!=-1) {
					if(dp[i+1][j]!=-1)dp[i+1][j]+=dp[i][j];
					if(dp[i][j+1]!=-1)dp[i][j+1]+=dp[i][j];
				}
			}
		}
		cout<<dp[b-1][a-1]<<endl;
	}
}