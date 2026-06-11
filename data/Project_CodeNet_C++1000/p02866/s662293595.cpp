#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000000000000
#define MOD 1000000007
typedef pair<int, int> P;

bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int mod_pow(int n, int p, int m) {
	if (p == 0) return 1;
	if (p % 2 == 0) {
		int t = mod_pow(n, p / 2, m);
		return (t * t) % m;
	}
	return n * mod_pow(n, p - 1, m) % m;
}
int extGCD(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long d = extGCD(b, a % b, y, x);
	y -= a / b * x;
	return d;
}
int modinv(int a, int m) {
	int b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
int digit(int x) {
	int cnt = 0;
	while (x > 0) {
		cnt += x % 10;
		x /= 10;
	}
	return cnt;
}

int cnt[100005];

signed main() {
	int n;
	cin >> n;
	int d[100005], ma = 0, ans = 1;
	rep(i, n) {
		cin >> d[i];
		cnt[d[i]]++;
		ma = max(ma, d[i]);
	}
	if (d[0] != 0 || cnt[0] != 1) {
		cout << 0 << endl;
		return 0;
	}
	rep(i, ma) {
		ans *= mod_pow(cnt[i], cnt[i + 1], 998244353);
		ans %= 998244353;
	}
	cout << ans << endl;


	return 0;
}
