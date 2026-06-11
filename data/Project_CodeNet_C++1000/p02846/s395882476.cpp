#include <bits/stdc++.h>

using namespace std;

#define ll long long

signed main() {
	int t1, t2;
	ll a1, a2, b1, b2;
	cin >> t1 >> t2;
	cin >> a1 >> a2;
	cin >> b1 >> b2;

	// 青木君がずっと原点にいるとして考える.
	a1 -= b1; a2 -= b2;
	if (a1 * t1 + a2 * t2 == 0)
		cout << "infinity" << endl;
	else if (a1 < 0 && a2 < 0)
		cout << 0 << endl;
	else if (a1 > 0 && a2 > 0)
		cout << 0 << endl;
	else if (abs(a1 * t1) > abs(a2 * t2))
		cout << 0 << endl;
	else {
		// b戻ってf進む、を繰り返す(b < f)
		ll b = abs(a1 * t1);
		ll f = abs(a2 * t2);
		if (b % (f - b))
			cout << (2 * (b / (f - b)) + 1) << endl;
		else
			cout << (2 * (b / (f - b))) << endl;
	}

	return 0;
}