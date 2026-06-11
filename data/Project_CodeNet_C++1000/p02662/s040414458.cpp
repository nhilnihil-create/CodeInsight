#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll dp[3010] = {0};
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		for (int j = m; j >= 0; j--){
			dp[j] = dp[j]*2%mod;
			if (j-x >= 0) dp[j] = (dp[j]+dp[j-x])%mod;
		}
		
	}
	printf("%lld\n", dp[m]);
	return 0;
}