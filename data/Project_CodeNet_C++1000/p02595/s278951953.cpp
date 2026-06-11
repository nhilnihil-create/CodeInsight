#include <iostream>

int main() {
	int N; long long D; std::cin >> N >> D;
	long long x, y;
	int count{ 0 };
	for (auto i{ 0 }; i < N; ++i) {
		std::cin >> x >> y;
		if (x * x + y * y <= D * D) ++count;
	}
	std::cout << count << std::endl;

	return 0;
}
