#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int A, B, M; std::cin >> A >> B >> M;
	int mina = 100000000;
	std::vector<int> a(A);
	for (auto& r : a) {
		std::cin >> r;
		if (mina > r) mina = r;
	}
	int minb = 100000000;
	std::vector<int> b(B);
	for (auto& r : b) {
		std::cin >> r;
		if (minb > r) minb = r;
	}
	std::vector<int> x(M);
	std::vector<int> y(M);
	std::vector<int> c(M);
	int min = 100000000;
	for (int i{ 0 }; i < M; ++i) {
		std::cin >> x[i] >> y[i] >> c[i];
		if (x[i] - 1 > A || x[i] - 1 > B) continue;
		int total = a[x[i] - 1] + b[y[i] - 1] - c[i];
		if (total < min) min = total;
	}

	std::cout << std::min(min, (mina + minb)) << std::endl;

	return 0;
}