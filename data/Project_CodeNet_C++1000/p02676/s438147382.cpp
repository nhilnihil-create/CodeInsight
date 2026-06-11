#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int K; std::cin >> K;
	std::string S; std::cin >> S;
	if (K < S.size()) {
		std::string ans;
		for (int i{ 0 }; i < K; ++i) {
			ans.push_back(S[i]);
		}
		std::cout << ans << "..." << std::endl;
	}
	else {
		std::cout << S << std::endl;
	}

	return 0;
}