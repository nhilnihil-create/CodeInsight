#include<iostream>
#include<cmath>

int main() {
	long long X, K, D;
	std::cin >> X >> K >> D;
	X = std::abs(X);

	long long ans;

	if (X / D >= K) {
		ans = X - K * D;
		std::cout << ans << std::endl;
		return 0;
	}

	long long A = K - X / D;
	if (A % 2 == 0) {
		ans = X - X / D * D;
	}
	else {
		ans = (X / D + 1) * D - X;
	}

	std::cout << ans << std::endl;

	return 0;
}