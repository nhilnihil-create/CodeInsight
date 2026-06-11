#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
ll LCM(ll x, ll y);

int main() {
	ll A, B, C, D, E, sum;
	cin >> A >> B >> C >> D;

	sum = 0;

	E = LCM(C, D);
	sum += B / C;
	sum -= (A - 1) / C;
	sum += B / D;
	sum -= (A - 1) / D;
	sum += (A - 1) / E;
	sum -= B / E;

	cout << B - A + 1 - sum;

	return 0;
}

ll LCM(ll x, ll y) {
	ll a,b,r, gcd, lcm;

	a = max(x, y);
	b = min(x, y);
	r = 1;

	while (r != 0) {
		r = a % b;
		if (r == 0) {
			gcd = b;
		}
		a = b;
		b = r;
	}

	lcm = x * y / gcd;

	return lcm;
}