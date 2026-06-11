#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int n, k;
	cin >> n >> k;
	int p[n + 1], c[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	bool vis[n + 1];
	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		memset(vis, false, sizeof vis);
		vector<int> pre;
		int curr = i;
		int sum = 0;
		while (!vis[curr]) {
			vis[curr] = true;
			pre.emplace_back(sum += c[curr]);
			curr = p[curr];
		}
		int len = pre.size();
		int t = k / len, m = k % len;
		for (int j = 2; j < len; j++)
			pre[j] = max(pre[j - 1], pre[j]);
		if (t >= 1) {
			ans = max(ans, pre[len - 1] - pre[0]);
			ans = max(ans, pre[m] - pre[0] + t * sum);
			ans = max(ans, pre[len - 1] - pre[0] + (t - 1) * sum);
		} else {
			ans = max(ans, pre[m] - pre[0]);
		}
	}
	cout << ans;
	return 0;
}
