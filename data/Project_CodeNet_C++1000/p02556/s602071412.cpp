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

	int n, x, y;
	cin >> n;
	int minx_plus_y = INT_MAX, maxx_plus_y = INT_MIN, minx_minus_y = INT_MAX, maxx_minus_y = INT_MIN;
	while (n--) {
		cin >> x >> y;
		maxx_plus_y = max(maxx_plus_y, x + y);
		minx_plus_y = min(minx_plus_y, x + y);
		maxx_minus_y = max(maxx_minus_y, x - y);
		minx_minus_y = min(minx_minus_y, x - y);
	}
	cout << max(maxx_plus_y - minx_plus_y, maxx_minus_y - minx_minus_y);
	return 0;
}