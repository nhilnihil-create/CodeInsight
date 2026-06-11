#include <iostream>
#include <vector>

int main() {
	unsigned long long N;
	std::cin >> N;
	std::vector<int> cumSum(60);
	cumSum.at(0) = 0;
	for (int i = 1; i < 60; ++i) {
		cumSum.at(i) = i + cumSum.at(i - 1);
	}
	int ans = 0;

	if (N == 1) {
		std::cout << 0 << std::endl;
		return 0;
	}

	unsigned long long X = N;
	for (unsigned long long i = 2; i * i < N ; ++i) {
		int cnt = 0;
		int iCum = 0;
		while (X % i == 0) {
			++cnt;
			X /= i;
			if (cnt >= cumSum.at(iCum+1)) {
				++iCum;
			}
		}
		ans += iCum;
		if (X == 1)
			break;
	}

	if (X>1)
		++ans;

	std::cout << ans << std::endl;
}