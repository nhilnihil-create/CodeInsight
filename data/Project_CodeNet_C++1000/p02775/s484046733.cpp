#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
char s[N];
int a[N];
int dp[N][2],n;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=n-1;i>=0;--i) a[i+1]=s[i]-'0';
	dp[n][0]=a[n];dp[n][1]=10-a[n];
	//printf("dp[%d][0]=%d,dp[%d][1]=%d\n",n,dp[n][0],n,dp[n][1]);
	for(int i=n-1;i>=0;--i){
		dp[i][0]=min(dp[i+1][0]+a[i],dp[i+1][1]+a[i]+1);
		dp[i][1]=min(9-a[i]+dp[i+1][1],10-a[i]+dp[i+1][0]);
		//printf("dp[%d][0]=%d,dp[%d][1]=%d\n",i,dp[i][0],i,dp[i][1]);
	}
	printf("%d",min(dp[1][0],dp[1][1]+1));
	return 0;
}