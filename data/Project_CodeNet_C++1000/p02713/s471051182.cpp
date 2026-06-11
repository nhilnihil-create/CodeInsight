#include <iostream>
#include <vector>
#include <map>
using namespace std;

const long MOD = 1'000'000'007;

long gcd(long a, long b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

long gcd(long a, long b, long c) {
	return gcd(gcd(a, b), c);
}

int main() {
	long n; cin >> n;
	long ans = 0;
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= n; j++) {
			for (long k = 1; k <= n; k++) {
				ans += gcd(i, j, k);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
