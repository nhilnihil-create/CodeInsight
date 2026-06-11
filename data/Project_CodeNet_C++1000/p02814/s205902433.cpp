#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	return a == 0 ? b : gcd(b % a, a);
}

int main() {
	long long n, m;
	cin >> n >> m;

	long long l = 1;
	long long pk = -1;
	bool ok = true;
	for (long long i = 0; i < n; ++i) {
		long long a;
		cin >> a;

		long long g = gcd(l, a);
		l = (l * a) / g;
		
		if (l > 2 * m) {
			ok = false;
			break;
		}

		long long k = 0;
		while (a % 2 == 0) {
			a /= 2;
			++k;
		}

		if (pk == -1) {
			pk = k;
		} else if (pk != k) {
			ok = false;
			break;
		}
	}

	if (!ok) {
		cout << 0;
		return 0;
	}

	long long ans = m / l;
	if ((m % l) >= (l / 2)) {
		++ans;
	}

	cout << ans;
	
	return 0;
}
	