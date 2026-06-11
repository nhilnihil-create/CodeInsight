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
	int ans = ((ll) mpow(10, n) + mpow(8, n)) % MOD;
	for (int rep = 0; rep < 2; ++rep) 
		ans = (ans - mpow(9, n) + MOD) % MOD;
	cout << ans << endl;
	return 0;
}