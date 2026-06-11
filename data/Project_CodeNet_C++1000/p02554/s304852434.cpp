#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int mpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (long long) res * a % MOD;
		a = (long long) a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main() {
	int n; cin >> n;
	cout << ((ll) mpow(10, n) + mpow(8, n) - 2 * mpow(9, n) + 2 * MOD) % MOD << endl;
	return 0;
}