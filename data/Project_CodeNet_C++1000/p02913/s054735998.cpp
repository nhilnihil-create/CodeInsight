#include <iostream>
#include <vector>

std::vector<long long> z_algorithm(std::string& s) {
	long long n = s.size();
	std::vector<long long> ret(n);
	ret[0] = n;
	long long cnt = 0;
	for (long long i = 1; i < n; i++) {
		for (long long j = i + cnt; j < n; j++) {
			if (s[j] != s[j - i]) {
				cnt = j - i;
				break;
			}
			if (j == n - 1) cnt = n - i;
		}
		ret[i] = cnt;
		if (cnt == 0) continue;
		for (long long j = i + 1; j < n; j++) {
			if (j - i + ret[j - i] < cnt) {
				ret[j] = ret[j - i];
				if (j == n - 1) return ret;
			}
			else {
				cnt -= j - i;
				i = j - 1;
				break;
			}
		}
	}
	return ret;
}

int main() {
	long long n;
	std::string s;
	std::cin >> n >> s;
	long long ans = 0;
	for (long long i = 0; i < n; i++) {
		std::string t = s.substr(i);
		std::vector<long long> v = z_algorithm(t);
		long long subans = 0;
		for (long long j = 0; j < v.size(); j++) {
			subans = std::max(subans, std::min(v[j], j));
		}
		ans = std::max(ans, subans);
	}
	std::cout << ans << std::endl;
}