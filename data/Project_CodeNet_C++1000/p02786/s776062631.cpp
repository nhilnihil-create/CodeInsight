#include <iostream>

int main() {
	long long int h;
	std::cin >> h;

	long long int pow = 1;
	long long int ans = 0;

	while (h > 0) {
		ans += pow;
		h /= 2;
		pow *= 2;
	}

	std::cout << ans;
}