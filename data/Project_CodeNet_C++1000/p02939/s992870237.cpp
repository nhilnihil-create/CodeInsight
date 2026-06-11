#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,dp[N][2];
char s[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(dp,~0x3f,sizeof(dp));
	dp[1][0]=1,dp[2][1]=1;
	if(s[1]^s[2])dp[2][0]=2;
	for(int i=3;i<=n;++i){
		dp[i][0]=dp[i-1][1]+1;
		if(s[i]^s[i-1])dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
		dp[i][1]=dp[i-2][0]+1;
	}
	printf("%d\n",max(dp[n][0],dp[n][1]));
	return 0;
}

