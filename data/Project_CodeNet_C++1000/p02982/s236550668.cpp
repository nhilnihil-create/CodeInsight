#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

bool is_integer(double x) {
	return std::floor(x) == x;
}

int main(){
	int N, D; std::cin >> N >> D;
	std::vector<std::vector<int>> X(N, std::vector<int>(D));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < D; ++j)
			std::cin >> X[i][j];
	int count = 0;
	for (int i = 0; i < N - 1; ++i) {
		for (int k = i + 1; k < N; ++k) {
			int total = 0;
			for (int j = 0; j < D; ++j)
				total += std::pow(X[i][j] - X[k][j], 2);
			if (is_integer(std::sqrt(total)))++count;
		}
	}
	std::cout << count << std::endl;

	return 0;
}