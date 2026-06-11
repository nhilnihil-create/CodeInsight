#include<iostream>
#include<string>

int main() {
	int N;
	std::cin >> N;
	std::string stone;
	std::cin >> stone;

	int count_R = 0;
	for (int i = 0; i < N; i++){
		if (stone[i] == 'R') {
			count_R++;
		}
	}

	int answer = 0;
	if (count_R == 0) {
		std::cout << 0 << std::endl;
		return 0;
	}
	for (int i = 0; i < count_R; i++) {
		if (stone[i] == 'W') {
			answer++;
		}
	}
	std::cout << answer << std::endl;
	return 0;
}