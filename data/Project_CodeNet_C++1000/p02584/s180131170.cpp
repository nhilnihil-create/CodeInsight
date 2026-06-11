#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { if (a % b == 0) { return b; } else { return gcd(b, a % b); } }

int main() {

	ll x, k, d;
	cin >> x >> k >> d;
	if (x < 0)x = -x;
	ll a, b, c;
	a = x % d;
	b = d - (x % d);
	c = x / d;
	ll ans;
	if (c > k) ans = x - k * d;
	else if ((k - c) % 2 == 0) ans = a;
	else ans = b;
	cout << ans;
	return 0;
}