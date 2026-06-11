#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	std::vector<std::vector<int>> A(3, std::vector<int>(3));
	std::vector<std::vector<int>> BOOL(3, std::vector<int>(3));
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			std::cin >> A[i][j];
	int N; std::cin >> N;
	std::vector<int> B(N);
	for (auto& r : B) std::cin >> r;
	for (int n = 0; n < N; ++n) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j) {
				if (B[n] == A[i][j])
					BOOL[i][j] = 1;
			}
	}
	if((BOOL[0][0] == 1 && BOOL[0][1] == 1 && BOOL[0][2] == 1)
		|| (BOOL[1][0] == 1 && BOOL[1][1] == 1 && BOOL[1][2] == 1)
		|| (BOOL[2][0] == 1 && BOOL[2][1] == 1 && BOOL[2][2] == 1)
		|| (BOOL[0][0] == 1 && BOOL[1][0] == 1 && BOOL[2][0] == 1)
		|| (BOOL[0][1] == 1 && BOOL[1][1] == 1 && BOOL[2][1] == 1)
		|| (BOOL[0][2] == 1 && BOOL[1][2] == 1 && BOOL[2][2] == 1)
		|| (BOOL[0][0] == 1 && BOOL[1][1] == 1 && BOOL[2][2] == 1)
		|| (BOOL[2][0] == 1 && BOOL[1][1] == 1 && BOOL[0][2] == 1))
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;
	return 0;
}