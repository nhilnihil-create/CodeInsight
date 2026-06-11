#include <iostream>
using namespace std;
const int N_MAX = 100000;

long long gcd(long long a, long long b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	while (a != 0) {
		long long tmp = b % a;
		b = a;
		a = tmp;
	}
	return b;
}

long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}

int factor2(long long x) {
	int i = 0;
	while (x % 2 == 0) {
		x /= 2;
		i++;
	}
	return i;
}

int main() {
	long long n, m, a[N_MAX], f;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] /= 2;
		if (i == 0) f = factor2(a[i]);
		else if (f != factor2(a[i])) {
			cout << 0 << endl;
			return 0;
		}
	}
	long long l = 1;
	for (int i = 0; i < n; i++) {
		l = lcm(l, a[i]);
		if (l > m) {
			cout << 0 << endl;
			return 0;
		}
	}
	long long ans = m / l / 2;
	if ((m/l)%2 == 1) ans++;
	cout << ans << endl;
	return 0;
}