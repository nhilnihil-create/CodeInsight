#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;


int modpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return res;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int n;
	cin >> n;
	cout << ((modpow(10, n) + modpow(8, n) - 2 * modpow(9, n)) % mod + mod) % mod;
	return 0;
}