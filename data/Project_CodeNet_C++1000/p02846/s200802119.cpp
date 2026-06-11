#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int64_t rll() {
	long long n;
	scanf("%lld", &n);
	return n;
}

int main() {
	int t1 = ri(), t2 = ri();
	int64_t a1 = rll(), a2 = rll();
	int64_t b1 = rll(), b2 = rll();
	int64_t a = a1 - b1;
	int64_t b = a2 - b2;
	int64_t a_dist = t1 * a;
	int64_t b_dist = t2 * b;
	if ((a_dist > 0) == (b_dist > 0)) {
		std::cout << 0 << std::endl;
		return 0;
	}
	int64_t one_dist = a_dist + b_dist;
	if (!one_dist) {
		std::cout << "infinity" << std::endl;
		return 0;
	}
	if ((a_dist > 0) == (one_dist > 0)) {
		std::cout << 0 << std::endl;
		return 0;
	}
	int64_t res = 1;
	res += (std::abs(a_dist) / std::abs(one_dist)) * 2;
	if (std::abs(a_dist) % std::abs(one_dist) == 0) res--;
	std::cout << res << std::endl;
	
	return 0;
}
