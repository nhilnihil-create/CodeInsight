#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//mod
const int mod = 1e9 + 7;
int powmod(int x, int y) { //x^y
	int rv = 1;
	for (; y > 0; y >>= 1, x = (long long) x * x % mod)
		if (y & 1)
			rv = (long long) rv * x % mod;
	return rv;
}

int n;
ll ans;

int main() {
	cin >> n;
	ans = powmod(10, n);
	ans -= powmod(9, n) * 2;
	ans += powmod(8, n);
	ans %= mod;
	if (ans < 0)
		ans += mod;
	cout << ans << endl;
}
