#include <bits/stdc++.h>

using namespace std;

#define int 		long long
#define endl 		"\n"
#define mod 		1000000007
#define inf 		1e18
#define IOS 		ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int32_t main() {

	IOS;

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}


	int mx = v[0].first + v[0].second, mn = v[0].first + v[0].second, ans = -1;

	for (int i = 1; i < n; i++) {
		mx = max(mx, v[i].first + v[i].second);
		mn = min(mn, v[i].first + v[i].second);
	}

	ans = max(ans, mx - mn);
	mx = v[0].first - v[0].second, mn = v[0].first - v[0].second;

	for (int i = 1; i < n; i++) {
		mx = max(mx, v[i].first - v[i].second);
		mn = min(mn, v[i].first - v[i].second);
	}

	ans = max(ans, mx - mn);

	cout << ans;

	return 0;
}