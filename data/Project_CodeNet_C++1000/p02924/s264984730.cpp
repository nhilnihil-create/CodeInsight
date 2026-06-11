#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

int main() {
	intt N; std::cin >> N;
	intt ans = 0;
	while (N != 0) {
		--N;
		ans += N;
	}
	std::cout << ans << std::endl;;
}