#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int ll

const int mx = 1e7 + 5;
const int MOD = 1e9 + 7;

int power(int a, int b) {
	int res = 1;

	while (b) {
		if (b % 2) {
			res = (res * a) % MOD;
		}

		a = (a * a) % MOD;
		b /= 2;
	}

	return res;
}

int inv(int a) {
	return power(a, MOD - 2);
}

int nCr(int a, int b) {
	if (a < b) return 0;
	int ans = 1;
	for (int i = a, j = 1; i >= a - b + 1; i--, j++) {
		ans = (ans * i) % MOD;
		ans = (ans * inv(j)) % MOD;
	}
	return ans;
}

signed main ()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b;
	cin >> n >> a >> b;

	cout << (power(2, n) - 1 - nCr(n, a) - nCr(n, b) + 2 * MOD) % MOD << endl;

	return 0;

}
