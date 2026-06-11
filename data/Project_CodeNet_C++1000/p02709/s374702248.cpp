#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using P = pair<long long,int>;
int n, a;
long long dp[2005][2005], ans;
P p[2005];
int main(){
	scanf("%d", &n);
	rep(i,n){
		scanf("%d", &a);
		p[i] = P{a, i};
	}
	sort(p, p+n, greater<P>());
	for(int i=1; i<=n; i++) for(int j=0; j<=i; j++){
		dp[i][j] =max((j?dp[i-1][j-1] + p[i-1].first * (p[i-1].second - (j-1)):0), (i!=j?dp[i-1][j] + p[i-1].first * (n-(i-j)-p[i-1].second):0));
	}
	rep(i,n+1) ans = max(ans, dp[n][i]);
	printf("%lld\n", ans);
}