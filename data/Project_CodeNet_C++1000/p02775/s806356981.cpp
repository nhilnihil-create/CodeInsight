#include <stdio.h>
#include <algorithm>
using namespace std;
char txt[1000003];
int dp[1000003][2]; //x , 10-x+1
int main(){
	scanf("%s",txt);
	int i=0;
	dp[0][0] = txt[i]-'0';
	dp[0][1] = 10-(txt[i]-'0')+1;
	for(i=1;txt[i];i++){
		int x = txt[i]-'0';
		dp[i][0] = min(dp[i-1][0],dp[i-1][1]) + x;
		dp[i][1] = min(dp[i-1][0] + 10-x+1,dp[i-1][1] + 10-x-1);
	}
	printf("%d",min(dp[i-1][0],dp[i-1][1]));
}