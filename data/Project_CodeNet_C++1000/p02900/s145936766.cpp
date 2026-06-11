#include "bits/stdc++.h"
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

long long lcm(long long x, long long y) {
	return x * y / gcd(x, y);
}

long long calc(long long N) {
	long long ret = 1;
	for (long long i = 2; i*i <= N; i++) {
		int m = 0;
		while (N%i == 0) { // 素数で割り切れなくなるまで割っていく
			m++;//割った個数を配列に足す
			N /= i;
		}
		if (0 != m) {
			ret++;
		}
		if (1 == N) {
			break;
		}
	}
	if (1 != N) {
		ret++;
	}

	return ret;
}

int main() {
	long long A, B;
	cin >> A >> B;
	long long GCD = gcd(A, B);
	cout << calc(GCD)<< endl;
	return 0;
}
