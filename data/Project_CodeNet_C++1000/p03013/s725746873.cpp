#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>
ll dp[100005];

int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll>c(n+1,2);
	ll buf(0);
	
	rep(i, m) {
		ll k;
		cin >> k;
		if (buf + 1 == k && i>=1) {
			cout << "0";
			return 0;
		}
		buf = k;
		c[k]=0;

	}
	ll mod = 1000000007;
	dp[0] = 1;
	rep(i, n+1) {
		if (i == 0)continue;
		if (c[i] == 0)continue;
		if (i == 1) {
			dp[i] = 1;
			continue;
		}
		dp[i] = dp[i - 2] + dp[i - 1];
		//cout << dp[i - 2]<<" " << dp[i - 1]<<" ";
		dp[i] %= mod;
		//cout << dp[i]<<i<<endl;
	}
	cout << dp[n];
	return 0;
}