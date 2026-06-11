#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
int n, s, a, md = 998244353;
long long dp[3005];
int main(){
	scanf("%d%d", &n, &s);
	dp[0] = 1;
	rep(i,n){
		scanf("%d", &a);
		for(int i=s; i>=0; i--) (dp[i] += dp[i] + (i>=a?dp[i-a]:0)) %= md;
	}
	printf("%lld\n", dp[s]);
}