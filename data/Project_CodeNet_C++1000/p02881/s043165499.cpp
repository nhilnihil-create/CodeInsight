#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main() {
	long long N; std::cin >> N;
	long long ans = N + 1 - 2;
	for (long long i = 1; i * i <= N; ++i)
		if (N % i == 0)
			ans = std::min(ans, i + (N / i) - 2);

	std::cout << ans << std::endl;

	return 0;
}
