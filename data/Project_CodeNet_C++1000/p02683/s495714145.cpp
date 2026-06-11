#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>
#include <queue>
#define _PI (3.141592653589793)
int main()
{
	int N, M, X;
	std::cin >> N >> M >> X;
	std::vector<int> C;
	std::vector<std::vector<int>> A;
	for (int i = 0; i < N; ++i) {
		int c;
		std::cin >> c;
		C.push_back(c);
		std::vector<int> row;
		for (int j = 0; j < M; ++j) {
			int a;
			std::cin >> a;
			row.push_back(a);
		}
		A.push_back(row);
	}
	int minsum = -1;
	for (int pattern = 0; pattern < (2 << N); ++pattern) {
		std::vector<int> AA;
		for (int i = 0; i < M; ++i) {
			AA.push_back(0);
		}
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			if ((pattern >> i) & 1) {
				sum += C[i];
				for (int j=0; j < M; ++j) {
					AA[j] += A[i][j];
				}
			}
		}
		int count = 0;
		for (int i = 0; i < M; ++i) {
			if (AA[i] >= X) {
				++count;
			}
		}
		if (count == M) {
			if ((minsum == -1) || (sum < minsum)) {
				minsum = sum;
			}
		}
	}
	std::cout << minsum << std::endl;
	return 0;
}