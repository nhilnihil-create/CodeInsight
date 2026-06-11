#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll l = lcm(c, d);
	ll x = b / c - a / c + (a % c == 0);
	ll y = b / d - a / d + (a % d == 0);
	ll z = b / l - a / l + (a % l == 0);
	ll ans = (b - a + 1) - (x + y - z);
	cout << ans << endl;
	return 0;
}