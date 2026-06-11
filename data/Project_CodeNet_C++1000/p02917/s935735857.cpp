#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
	int N; std::cin >> N;
	std::vector<int> B(N - 1);
	for (auto& r : B) std::cin >> r;

	int sum = B[0] + B[N - 2];
	for (int i = 0; i < N - 2; ++i)
		sum += std::min(B[i], B[i + 1]);
	std::cout << sum << std::endl;

	return 0;
}