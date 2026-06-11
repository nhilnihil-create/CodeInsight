#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

const int NINF = -999999;
int len;
char str[200005];
int dp[200005][2];

int main(){
	scanf("%s", str);
	len = strlen(str);
	dp[0][0] = 1;
	dp[0][1] = NINF;
	for(int i = 1; i < len; i++){
		// length 1
		dp[i][0] = NINF;
		if(str[i] != str[i - 1]){
			dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
		}
		dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
		// length 2
		if(i == 1){
			dp[i][1] = 1;
		}else{
			dp[i][1] = NINF;
		}
		if(i > 1){
			dp[i][1] = max(dp[i][1], dp[i - 2][0] + 1);
		}
		if(i > 2 && str[i] != str[i - 2] && str[i - 1] != str[i - 3]){
			dp[i][1] = max(dp[i][1], dp[i - 2][1] + 1);
		}
	}
	printf("%d\n", max(dp[len - 1][0], dp[len - 1][1]));
	return 0;
}