#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int N; std::cin >> N;
	std::vector<int> D(N);
	std::vector<int> DD(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> D[i];
		--D[i];
	}
	for (int i = 0; i < N; ++i)
		DD[D[i]] = i;
	for (int i = 0; i < N; ++i)
		std::cout << DD[i] + 1 << " ";

	return 0;
}