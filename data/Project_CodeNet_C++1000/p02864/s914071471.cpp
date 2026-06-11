#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;

LL dp[505][505] = {0};
LL n,k,a[505],ans = INF;

int main(){
	memset(dp,0x3f,sizeof(dp));
	cin >> n >> k;
	for(LL i = 1;i <= n;i ++){
		cin >> a[i];
		dp[i][0] = 0;
	} dp[0][0] = 0;
	for(LL j = 1;j <= n - k;j ++){
		for(LL i = 0;i <= n;i ++){
			for(LL l = i + 1;l <= n;l ++){
				dp[i][j] = min(dp[i][j],dp[l][j - 1] + max(0LL,a[l] - a[i]));	
			}
		}
	}
	cout << dp[0][n - k] << endl;
	return 0;
}