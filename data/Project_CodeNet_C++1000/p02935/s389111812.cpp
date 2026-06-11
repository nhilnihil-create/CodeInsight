#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int N; std::cin >> N;
	std::vector<double> v(N);
	for (auto& r : v) std::cin >> r;
	std::sort(v.begin(), v.end());
	double ans = v[0];
	for (int i = 1; i < N; ++i)
		ans = (ans + v[i]) / 2;
	std::cout << ans << std::endl;

	return 0;
}