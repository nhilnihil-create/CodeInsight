#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
//see answer

//最大公約数
long long gcd(long long a, long long b) {
	return (b == 0 ? a : gcd(b, a % b));
}
//最小公倍数
long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}

int main() {
	long long N, M;
	cin >> N >> M;
	long long B = 1;
	long long A;
	cin >> A;
	A /= 2;
	B = A;
	int C = 1;
	while (A % 2 == 0) {
		A /= 2;
		C++;
	}
	bool ans = true;
	for (int i = 1; i < N; i++) {
		cin >> A;
		A /= 2;
		B = lcm(A, B);
		int c = 1;
		while (A % 2 == 0) {
			A /= 2;
			c++;
		}
		if (C != c) ans = false;
	}
	cout << (ans ? ((M / B) + 1) / 2 : 0) << endl;
}