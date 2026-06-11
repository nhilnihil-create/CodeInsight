#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < (ll)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int n, m, q, ans = 0;
int a[50], b[50], c[50], d[50];

void dfs(vector<int> x) {
	if ((int)x.size() == n + 1) {
		int sum = 0;
		rep(i, q) {
			if (x[b[i]] - x[a[i]] != c[i]) continue;
			sum += d[i];
		}
		ans = max(ans, sum);
		return;
	}
	x.push_back(x.back());
	while (x.back() <= m) {
		dfs(x);
		x.back()++;
	}
}

int main() {
	cin >> n >> m >> q;
	rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];
	dfs(vector<int> (1, 1));
	cout << ans << endl;
	return 0;
}
