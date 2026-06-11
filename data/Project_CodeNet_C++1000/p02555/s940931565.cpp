#include<cstdio>
using namespace std;
int s;
long long dp[2005];
int main() {
	scanf("%d",&s);dp[0]=1;
	for(int i=3;i<=s;++i) {
		for(int j=0;j<=i-3;++j) {
			dp[i]=(dp[i]+dp[j])%1000000007;
		}
	}
	printf("%lld",dp[s]);
	return 0;
}