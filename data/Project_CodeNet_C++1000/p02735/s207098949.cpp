// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9;

int n,m;
char s[105][105];
int dp[105][105];

signed main(){
	memset(dp,127,sizeof dp);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	dp[1][1] = s[1][1] == '#';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i == j && i == 1)continue;
			if(j >= 2){
				if(s[i][j] == '#' && s[i][j-1] == '.' && j>=2)
					dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
				else dp[i][j] = min(dp[i][j], dp[i][j-1]);
			}
			if(i >= 2){
				if(s[i][j] == '#' && s[i-1][j] == '.' && i>=2)
					dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
				else dp[i][j] = min(dp[i][j], dp[i-1][j]);
			}
		}
	}
	printf("%d\n",dp[n][m]);

	return 0;
}

