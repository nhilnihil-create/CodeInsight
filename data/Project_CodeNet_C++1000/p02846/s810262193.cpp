//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>
#include <string>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define mpa make_pair
#define all(a) (a).begin(), (a).end()

int sign(ll x) {
	return  int(x / abs(x));
}

int main() {
	ll t1, t2, a1, a2, b1, b2;
	cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
	ll a = a1 - b1, b = a2 - b2;
	if (a * t1 + b * t2 == 0) {
		cout << "infinity" << endl;
		return 0;
	}
	if (sign(t1*a)*sign(t1*a + t2 * b) > 0) {
		cout << 0 << endl;
	}
	else {
		ll ans = 0;
		if (abs(t1*a) % abs(t1*a + t2 * b)) {
			ans = 1;
		}
		ans += abs(t1*a) / abs(t1*a + t2 * b) * 2;
		cout << ans << endl;
	}
	return 0;
}