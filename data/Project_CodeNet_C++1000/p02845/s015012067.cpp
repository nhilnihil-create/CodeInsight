#include <bits/stdc++.h>
using namespace std;

const int nm = 1e5, mod = 1e9 + 7;
int n, c[nm + 1];
long long ans = 1;

int main() {
	c[0] = 3;
	cin >> n;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		ans = ans * c[a] % mod;
		c[a]--, c[a + 1]++;
	}
	cout << ans << endl;
}
