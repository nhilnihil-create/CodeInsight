#include "bits/stdc++.h"
using namespace std;

long long gcd(long  long a, long long b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

long lcm(long long x, long long y) {
	return x / gcd(x, y)*y;
}

int f(int x) {
	int res = 0;
	while (x % 2 == 0) {
		x /= 2;
		res++;
	}
	return res;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int n = 0; n < N; ++n) {
		int m;
		cin >> m;
		A[n] = m/2;
	}
	int t = f(A[0]);
	for (int n = 0; n < N; ++n) {
		if (t != f(A[n])) {
			cout << 0 << endl;
			return 0;
		}
		A[n] >> t;
	}
	M >> t;
	long long l = 1;
	for (int n = 0; n < N; ++n) {
		l = lcm(l, (long long)A[n]);
		if (l > M) {
			cout << 0 << endl;
			return 0;
		}
	}
	
	cout << ( 1 + M / l)/2 <<endl;
	return 0;
}