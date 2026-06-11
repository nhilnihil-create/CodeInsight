#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>

int main() {
	std::string S, T;
	std::cin >> S >> T;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] != T[i]) {
			std::cout << "No" << std::endl;
			return 0;
		}
	}
	std::cout << "Yes" << std::endl;
	return 0;
}