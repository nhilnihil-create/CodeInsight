#include <bits/stdc++.h>
#define MAX (ll)(1e5 + 4)
#define MOD (ll)(1e9 + 7)
#define INF (ll)(1e18 + 3)
#define PI (double)(3.14159265)

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ll t1, t2, a1, a2, b1, b2;
	cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
	ll s = (a1 - b1) * t1, ss = (a2 - b2) * t2;
	if (s + ss == 0) {
		cout << "infinity\n";
		return 0;
	}
	if (((s < 0 && ss > 0) || (ss < 0 && s > 0)) && abs (ss) > abs (s)) {
		ss = abs (ss), s = abs (s);
		ll d = abs (ss) - abs (s);
		cout << 2 * (s / d) + ((s % d) > 0) << "\n";
	}
	else {
		cout << "0\n";
	}
}
