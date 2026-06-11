#include <iostream>
#include <string>

using namespace std;

long long t1, t2, a1, a2, b1, b2;

long solve(long long s, long long n, long long p) {
	cout << s << " " << n << " " << p << endl;
	if (n == s)
		return 1;
	else if (n > s)
		return solve(n - s, p, n) + 1;
	else
		return 0;
}

long long gcd(long long c1, long long c2) {
	long long d = c2 - c1;
	long long n = c1 / d;
	if (c1 % d == 0)
		return n * 2;
	else
		return n * 2 + 1;
}

int main() {
	long long c1, c2;
	cin >> t1 >> t2;
	cin >> a1 >> a2;
	cin >> b1 >> b2;

	if ((a1 > b1 && a2 > b2) || (a1 < b1 && a2 < b2)) {
		cout << 0;
	} else {
		if (a1 < b1) {
			c1 = t1 * (b1 - a1);
			c2 = t2 * (a2 - b2);
		} else {
			c1 = t1 * (a1 - b1);
			c2 = t2 * (b2 - a2);
		}
		if (c1 == c2)
			cout << "infinity";
		else if (c1 > c2)
			cout << 0;
		else
			cout << gcd(c1, c2);
	}
	cout << endl;
    return 0;
}
