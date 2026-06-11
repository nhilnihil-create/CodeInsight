#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 * 2 + 10, INF = 1e9 * 1e9 + 10, MOD = 1e9 + 7;

ll dp[2005][2005];

int main()
{
	fastInp;

	ll n;
	cin >> n;
	vector<ll> vec(n);
	vector<pair<ll, ll>> vec2;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		vec2.push_back({ vec[i], i });
	}

	sort(vec2.rbegin(), vec2.rend());

	ll ans = 0;
	for (int x = 0; x <= n; x++) {
		for (int j = 1; j <= n; j++) {
			if (j - x < 0) continue;

			ll y = j - x, ind = (x + y) - 1, k = 0, k2 = 0;
			if (x + y > n) continue;
			ll vl = 0, vl2 = 0;
			if (x > 0) vl = dp[x - 1][y];
			if (y > 0) vl2 = dp[x][y - 1];

			if (x != 0) k = abs(vec2[ind].second - (x - 1)) * vec2[ind].first;
			if (y != 0) k2 = abs(vec2[ind].second - (n - y)) * vec2[ind].first;
			dp[x][y] = max(vl + k, vl2 + k2);
			if (x + y == n) ans = max(ans, dp[x][y]);
		}
	}
	cout << ans;
	return 0;
}