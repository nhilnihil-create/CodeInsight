#include <iostream>
#include <vector>
#include <cmath>

/*std::vector<long long> divisors(long long n) {
	std::vector<long long> ret(1, 1);
	long long m = sqrt(n);
	for (long long i = 2; i <= m; i++) {
		if (n % i == 0) ret.push_back(i);
	}
	if (m == sqrt(n)) {
		for (long long i = ret.size() - 2; i >= 0; i--) {
			ret.push_back(n / ret[i]);
		}
	} else {
		for (long long i = ret.size() - 1; i >= 0; i--) {
			ret.push_back(n / ret[i]);
		}
	}
	return ret;
}*/

std::vector<long long> common_divisors(long long a, long long b) {
	auto divisors = [] (long long n) {
		std::vector<long long> ret(1, 1);
		long long m = sqrt(n);
		for (long long i = 2; i <= m; i++) {
			if (n % i == 0) ret.push_back(i);
		}
		if (m == sqrt(n)) {
			for (long long i = ret.size() - 2; i >= 0; i--) {
				ret.push_back(n / ret[i]);
			}
		} else {
			for (long long i = ret.size() - 1; i >= 0; i--) {
				ret.push_back(n / ret[i]);
			}
		}
		return ret;
	};
    if (a > b) std::swap(a, b);
    std::vector<long long> v = divisors(a);
    std::vector<long long> ret(1, 1);
    for (long long i = 1; i < v.size(); i++) {
        if (b % v[i] == 0) ret.push_back(v[i]);
    }
    return ret;
}

bool is_prime(long long n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
	long long m = sqrt(n);
    for (long long i = 3; i <= m; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    long long a, b;
    std::cin >> a >> b;
    std::vector<long long> v = common_divisors(a, b);
    long long ans = 1;
    for (auto i : v) {
        if (is_prime(i)) ans++;
    }
    std::cout << ans << std::endl;
}