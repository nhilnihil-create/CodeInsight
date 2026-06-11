#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

ll gcd(ll a, ll b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	ll A, B, C, D;
	cin >> A >> B >> C >> D;

	ll ans = B - A + 1;
	ll tmp = (B / C - (A-1) / C) + (B / D - (A-1) / D) - (B / lcm(C, D) - (A-1) / lcm(C, D));

	cout << ans - tmp << endl;
	return 0;
}
