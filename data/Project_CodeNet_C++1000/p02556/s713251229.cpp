#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(false);

	int n; cin >> n;
	ll maxP, minP, maxS, minS;
	maxP = maxS = INT_MIN;
	minP = minS = INT_MAX;
	REP(i, n) {
		ll x, y; cin >> x >> y;
		maxP = max(maxP, x + y);
		minP = min(minP, x + y);
		maxS = max(maxS, x - y);
		minS = min(minS, x - y);
	}
	cout << max(maxP - minP, maxS - minS) << '\n';
    return 0;
}
