#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long GetGreatestCommonDivisor(long long a, long long b)
{
	long long m = a;
	long long n = b;
	long long temp;
	while (m % n != 0) {
		temp = n;
		n = m % n;
		m = temp;
	}
	return n;
}

vector<pair<long long, long long> > prime_factorize(long long N) {
	vector<pair<long long, long long> > res;
	for (long long a = 2; a * a <= N; ++a) {
		if (N % a != 0) continue;
		long long ex = 0; // 指数

		 // 割れる限り割り続ける
		while (N % a == 0) {
			++ex;
			N /= a;
		}

		// その結果を push
		res.push_back({ a, ex });
	}

	// 最後に残った数について
	if (N != 1) res.push_back({ N, 1 });
	return res;
}

int main() {

	ll a, b; cin >> a >> b;
	ll gcd = GetGreatestCommonDivisor(a, b);
	vector<pair<long long, long long>> a_prime;  // a^x ならば { a, x }
	a_prime = prime_factorize(gcd);
	cout << a_prime.size() + 1 << endl;
	return 0;
}