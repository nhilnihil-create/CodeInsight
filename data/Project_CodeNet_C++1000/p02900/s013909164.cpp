#include <iostream>
#include <vector>
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

vector<pair<long long, int>> prime_factorization(long long n) {
	vector<pair<long long, int>> v;
	for (long long i = 2; i * i <= n; ++i) {
		int e = 0;
		while (n % i == 0) {
			++e;
			n /= i;
		}
		if (e != 0) v.emplace_back(i, e);
	}
	if (n != 1) v.emplace_back(n, 1);
	return v;
}

int main() {
	long long a, b;
	cin >> a >> b;
	auto v = prime_factorization(gcd(a, b));
	long long ans = 1 + v.size();
	cout << ans << endl;
	return 0;
}