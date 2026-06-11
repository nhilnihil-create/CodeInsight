#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINK: INT vs LONG LONG?

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll ans = 1;
	int a, b;
	cin >> a >> b;
	int c, d;
	cin >> c >> d;

	// neg, neg - choose most negative
	ans = max({(ll) a * c, (ll) a * d, (ll) b * c, (ll) b * d});
	cout << ans << endl;
	// ll p1 = (ll) a * c;
	// ll p2 = (ll) a * d;
	// ll p

	return 0;
}