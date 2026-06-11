#include<iostream>

int main() {
	int N;
	long long D;
	std::cin >> N >> D;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		long long X, Y;
		std::cin >> X >> Y;
		if (X * X + Y * Y <= D * D) {
			answer++;
		}
	}
	std::cout << answer << std::endl;
	return 0;
}