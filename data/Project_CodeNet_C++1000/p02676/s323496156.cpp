#include<iostream>
#include<string>

int main() {
	int K;
	std::string S;
	std::cin >> K >> S;
	if (S.size() <= K) std::cout << S << std::endl;
	else {
		for (int i = 0; i < K; i++) {
			std::cout << S[i];
		}
		std::cout << "..." << std::endl;
	}
	return 0;
}