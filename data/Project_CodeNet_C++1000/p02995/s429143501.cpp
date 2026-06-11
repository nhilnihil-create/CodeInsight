#include <iostream>
using namespace std;

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

long long f(long long x, long long c, long long d) {
	long long res = x;
	res -= x / c;
	res -= x / d;
	res += x / lcm(c, d);
	return res;
}

int main() {
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	long long ans = f(b,c,d) - f(a-1,c,d);
	cout << ans << endl;
	return 0;
}