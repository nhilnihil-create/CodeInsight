#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <cassert>
#include <random>
using namespace std;
using ll = long long;


ll dp[302][302][302];
void chmin(ll &a, ll b) {
	a = min(a, b);
}

int main() {
	int n, k; cin >> n >> k;
	vector<ll> h(n + 2);
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int s = 0; s <= n; s++) {
				dp[i][j][s] = 1e18;
			}
		}
	}
	map <ll, int> mp;
	mp[0] = 0;
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		if (mp.count(h[i])) continue;
		mp[h[i]] = cnt++;
	}
	vector<int> mp2(n + 2);
	for (int i = 0; i <= n; i++) {
		mp2[i] = mp[h[i]];
	}
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int t = 0; t <= n; t++) {
				chmin(dp[i][j][mp2[i]], dp[i - 1][j][mp2[t]] + max(0LL, h[i] - h[t]));
			}
			if (j == 0) continue;
			for (int s = 0; s <= n; s++) {
				chmin(dp[i][j][mp2[s]], dp[i - 1][j - 1][mp2[s]]);
			}
		}
	}
	ll ans = 1e18;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			chmin(ans, dp[n][i][mp2[j]]);
		}
	}
	cout << ans << endl;
	return 0;
}
