#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int N, M; std::cin >> N >> M;

	//高さの入力
	std::vector<int> H(N);
	for (auto& r : H) std::cin >> r;

	//道の入力
	std::vector<int> A(M);
	std::vector<int> B(M);
	for (auto i{ 0 }; i < M; ++i)
		std::cin >> A[i] >> B[i];

	std::vector<bool> flag(N);
	std::fill(flag.begin(), flag.end(), true);
	int count{ 0 };
	for (auto i{ 0 }; i < M; ++i) {
		if (H[A[i]-1] == H[B[i]-1]) {
			flag[A[i]-1] = false;
			flag[B[i]-1] = false;
		}
		else if (H[A[i]-1] < H[B[i]-1])
			flag[A[i]-1] = false;
		else
			flag[B[i]-1] = false;
	}
	for (bool b : flag)
		if (b)
			++count;

	std::cout << count << std::endl;

	return 0;
}