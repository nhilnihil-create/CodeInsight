#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
long long n;
long long k;
long long s = 1, s1 = 1, s2 = 1, s3, s4;

long long C (long long n, long long m) {
	return n * (n - 1) / 2;
}

int main () {
	cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		s = s * 10 % MOD;
		s %= MOD;
	}
	for (int i = 1; i <= n; i ++ ) {
		s1 = s1 * 9 % MOD;
		s1 %= MOD;
	}
	for (int i = 1; i <= n; i ++ ) {
		s2 = s2 * 8 % MOD;
		s2 % MOD;
	}
	s = s + MOD;
	long long s4 = s - (s1 * 2 - s2) % MOD;
	s4 %= MOD;
	cout << s4 << endl;
	return 0;
}
