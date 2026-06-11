#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

int main(){
	intt N, K; std::cin >> N >> K;
	std::vector<intt> A(N);
	for (auto& r : A) {
		std::cin >> r;
		++r;
	}
	std::vector<intt> S(N + 1, 0);
	for (int i = 0; i < N; ++i)
		S[i + 1] = S[i] + A[i];
	intt ans = 0;
	for (intt i = 0; i + K <= N; ++i)
		ans = std::max(ans, S[i + K] - S[i]);
	std::cout << std::fixed << std::setprecision(12) << (double)(ans) / 2 << std::endl;

}