#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;

const ll N = 3010;
const ll p = 998244353;
ll n, s;
ll a[N];
ll f[N][N];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];

	f[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= s; j++) {
			f[i + 1][j] += f[i][j] * 2 % p, f[i + 1][j] %= p;
			if (j + a[i + 1] <= s) f[i + 1][j + a[i + 1]] += f[i][j], f[i][j + a[i + 1]] %= p;
		}
	}
	cout << f[n][s] << endl;

	return 0;
}