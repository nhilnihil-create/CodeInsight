#include <iostream>
#include <cstdlib>
#include <algorithm>

const long M = 1000000007;

int pow_mod(int x, long expo) {
	long c = 1;
	for (int i = 0; i < expo; i++) {
		c = (c * x) % M;
	}

	return c;
}


int main() {
	long n;
	long long all, exclude, ans;

	std::cin >> n;
	all = pow_mod(10, n) % M;
	exclude = (((2 * (pow_mod(9, n) % M)) % M) - (pow_mod(8, n) % M)) % M;
	ans = (all - exclude) % M;
	ans = (ans + M) % M;

	std::cout << ans << "\n";

	return 0;
}