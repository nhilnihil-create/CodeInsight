#include <cstdio>
#include <iostream>

using namespace std;

typedef unsigned long long ullong;

const long M = 1000000007;

ullong power(ullong n, ullong m) {
	if (m == 0)
		return 1;

	ullong res = power(n, m / 2);
	if (m % 2 == 0) {
		res = res * res % M;
	} else {
		res = (res * res % M) * n % M;
	}

	return res;
}

int main() {

	int m, n;
	scanf("%d %d", &m, &n);

	cout << power(m, n) << endl;

	return 0;
}