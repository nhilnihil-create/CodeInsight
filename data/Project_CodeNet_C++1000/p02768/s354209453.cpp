#include <bits/stdc++.h>
using namespace std;

const int com = 1000000007;

int power(long long a, long long b) {
	int c = 1;
	while (b) {
		if (b & 1) c = c * a % com;
		a = a * a % com;
		b >>= 1;
	}
	return c;
}

int nCr(int a, int b) {
	long long x = 1, y = 1;
	for (int i = 0; i < b; i++) {
		x = x * (a - i) % com;
		y = y * (i + 1) % com;
	}
	return x * power(y, com - 2) % com;
}

int main() {
	int n, a, b;
	cin >> n >>  a >> b;

	int ans = power(2, n) - 1 - nCr(n , a) - nCr(n , b);

	cout << (ans % com + com) % com;
	return 0;
}