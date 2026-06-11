#include<bits/stdc++.h>
#define N 200100
using namespace std;
int dp[N][2];
char s[N];
int main(){
	memset(dp,-1,sizeof(dp));
	dp[0][0]=dp[0][1]=0;
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;s[i];i++){
		if(i>=2){
			if(dp[i-2][0]>=0) dp[i][1]=max(dp[i][1],dp[i-2][0]+1);
			if(dp[i-2][1]>=0 && i>=4 && (s[i]!=s[i-2] || s[i-1]!=s[i-3])) dp[i][1]=max(dp[i][1],dp[i-2][1]+1);
		}
		if(i>=1){
			if(dp[i-1][1]>=0) dp[i][0]=max(dp[i][0],dp[i-1][1]+1);
			if(dp[i-1][0]>=0 && i>=2 && s[i]!=s[i-1]) dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
		}
		//printf("%d %d\n",dp[i][0],dp[i][1]);
	}
	printf("%d\n",max(dp[n][0],dp[n][1]));
	return 0;
}