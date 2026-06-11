
// E - Dist Max

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	ll min_X = INF;
	ll max_X = -INF;
	ll min_Y = INF;
	ll max_Y = -INF;
	for (int i=0; i<N; i++) {
		ll x, y, X, Y;
		cin >> x >> y;
		X = x - y;
		Y = x + y;
		min_X = min(min_X, X);
		max_X = max(max_X, X);
		min_Y = min(min_Y, Y);
		max_Y = max(max_Y, Y);
	}

	ll ans = max(max_X - min_X, max_Y - min_Y);

	cout << ans << endl;

	return 0;
}