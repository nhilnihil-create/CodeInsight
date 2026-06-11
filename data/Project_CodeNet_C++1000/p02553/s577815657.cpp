#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINK: INT vs LONG LONG?

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a, b, c, d; cin >> a >> b >> c >> d;
	ll ans = max({a * c, a * d, b * c, b * d});
	cout << ans << endl;

	return 0;
}