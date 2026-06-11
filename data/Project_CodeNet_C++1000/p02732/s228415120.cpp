#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

intt N;

intt func(intt& p) {
	return p * (p - 1) / 2;
}

int main() {
	std::cin >> N;
	intt ans = 0;
	std::vector<intt> A(N);
	std::map<intt, intt> MAP;
	for (auto& r : A) {
		std::cin >> r;
		++MAP[r];
	}
	for (auto& r : MAP)
		if (r.second > 1) {
			ans += func(r.second);
		}
	for (intt i = 0; i < N; ++i) {
		if (MAP[A[i]] > 1) {
			intt l = func(MAP[A[i]]);
			--MAP[A[i]];
			intt r = func(MAP[A[i]]);
			std::cout << ans - l + r << std::endl;
			++MAP[A[i]];
		}
		else
			std::cout << ans << std::endl;
	}


	return 0;
}