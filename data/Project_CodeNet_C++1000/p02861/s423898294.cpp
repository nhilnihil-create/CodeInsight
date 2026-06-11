#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

int facctorialMethod(int k) {
	int sum = 1;
	for (int i = 1; i <= k; ++i)
	{
		sum *= i;
	}
	return sum;
}

int main() {
	long long N; std::cin >> N;
	double mean = 0;
	long long count = facctorialMethod(N);
	std::vector<std::pair<double, double>> XY(N);
	for (auto& r : XY)
		std::cin >> r.first >> r.second;
	std::sort(XY.begin(), XY.end());
	do {
		for (int i = 0; i < N - 1; ++i)
			mean += std::sqrt(std::pow(XY[i].first - XY[i + 1].first, 2) + std::pow(XY[i].second - XY[i + 1].second, 2));
	} while (std::next_permutation(XY.begin(), XY.end()));
	std::cout << std::setprecision(10) << mean / count << std::endl;

	return 0;
}
