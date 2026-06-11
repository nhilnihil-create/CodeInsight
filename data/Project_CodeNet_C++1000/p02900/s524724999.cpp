#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isPrime(int n) {
	if (n <= 1) return 0;
	if (n == 2 || n == 3) return 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;
	for (int i = 5; i * i <= n; i += 6) {
		if(n % i == 0 || n % (i + 2) == 0) return 0;
	}
	return 1;
}

signed main() {
#ifdef _DEBUG
	freopen("_in" , "r", stdin );
	freopen("_out", "w", stdout);
#endif
	int a, b; cin >> a >> b;
	int n = __gcd(a, b), c = 1, ans = 1;
	int t = n;
	while (t != 1) {
		c++; if(c * c > n) break;
		if (t % c == 0) ans++;
		while (t % c == 0) t /= c;
	}
	if (isPrime(t)) ans++;
	cout << ans << '\n';
}
