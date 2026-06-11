#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld PIE = atan2(0, -1);
const ll MOD = 1e9 + 7;
const int MAXN = 2e3 + 5;

int n;
int a[MAXN];
ll dp[MAXN][MAXN];

bool cmp(int i, int j) {
	return a[i] > a[j];
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	vector<int> indices;
	for (int i = 0; i < n; ++i) indices.push_back(i);
	sort(indices.begin(), indices.end(), cmp);
	dp[1][0] = abs(indices[0] - 0) * 1ll * a[indices[0]];
	dp[0][0] = abs(indices[0] - n + 1) * 1ll * a[indices[0]];
	for (int i = 1; i < n; ++i) {
		int ind = indices[i];
		int activeness = a[ind];
		for (int prevleft = 0; prevleft <= i; ++prevleft) {
			int lpos = prevleft, rpos = n - (i - prevleft) - 1;
			ll curval = dp[prevleft][i - 1];
			dp[prevleft][i] = max(dp[prevleft][i], curval + abs(rpos - ind) * 1ll * activeness);
			dp[prevleft + 1][i] = max(dp[prevleft + 1][i], curval + abs(lpos - ind) * 1ll * activeness);
		}
	}
	ll ans = 0;
	for (int i = 0; i <= n; ++i) {
		ans = max(ans, dp[i][n - 1]);
	}
	cout << ans << "\n";
}

int main() {
	solve();
	return 0;
}