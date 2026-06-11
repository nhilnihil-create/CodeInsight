#include<iostream>

int main() {
	int K;
	std::cin >> K;

	int mod = 7 % K;
	int answer = 1;
	int count = 1;
	while (mod != 0) {
		count++;
		if (count > K) {
			std::cout << -1 << std::endl;
			return 0;
		}
		answer++;
		mod = (10 * mod + 7) % K;
	}

	std::cout << answer << std::endl;
	return 0;
}