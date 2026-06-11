//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	cin >> n >> m;
	vector<ll>	aa(m);
	for(i=0;i<m;i++) cin >> aa[i];
	vector<ll> dp(n+1);
	dp[0] = 1;
	for(i=1,a=0;i<=n;i++) {
		if (a<m)
			if (aa[a] == i) {
				a++;
				continue;
			}
		dp[i] = dp[i-1];
		if (i>1) dp[i] += dp[i-2];
		dp[i] %= 1000000007;
	}

	cout << dp[n] << endl;
	return 0;
}
