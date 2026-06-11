#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int N; std::cin >> N;
	std::vector<int> P(N);
	std::vector<int> Q(N);
	std::vector<int> J(N);
	for (auto& r : P) std::cin >> r;
	for (auto& rr : Q) std::cin >> rr;
	for (int i = 0; i < N; ++i)
		J[i] = i + 1;

	std::sort(J.begin(), J.end());
	bool  flag_p = false;
	int i = 0;
	do {
		flag_p = false;
		++i;
		for (int j = 0; j < N; ++j)
			if (P[j] != J[j])
				flag_p = true;
		if (flag_p == false)break;
	} while (std::next_permutation(J.begin(), J.end()));

	std::sort(J.begin(), J.end());
	bool flag_q = false;
	int ii = 0;
	do {
		flag_q = false;
		++ii;
		for (int jj = 0; jj < N; ++jj)
			if (Q[jj] != J[jj])
				flag_q = true;
		if (flag_q == false)break;
	} while (std::next_permutation(J.begin(), J.end()));
	std::cout << std::abs(i - ii) << std::endl;

	return 0;
}