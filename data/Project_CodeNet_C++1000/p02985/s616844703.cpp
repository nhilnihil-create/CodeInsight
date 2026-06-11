#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 1e5+5, MOD = 1e9+7;
int n,k;
vector<int> g[MAXN];
long long dp[MAXN];

void dfs(int x, int p) {
	long long cur = (x==1?k-1:k-2);
	for (auto i: g[x]) {
		if (i==p) continue;
		dp[i] = cur;
		cur--;
		dfs(i,x);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n-1; ++i) {
		int a,b;
		cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	long long ans = 1;
	dp[1] = k;
	dfs(1,-1);
	for (int i = 1; i <= n; ++i) {
		//cerr << dp[i] <<' ';
		ans = ans % MOD * dp[i] % MOD;
		ans %= MOD;
	}
	cout << ans % MOD;
    return 0;
}
