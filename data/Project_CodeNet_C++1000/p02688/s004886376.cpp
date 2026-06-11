#include<iostream>
#include<vector>

int main() {
	int N, K;
	std::cin >> N >> K;
	std::vector<int> snuke(N);
	for (int i = 0; i < K; i++) {
		int d;
		std::cin >> d;
		for (int j = 0; j < d; j++) {
			int A;
			std::cin >> A;
			snuke[A - 1]++;
		}
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		if (snuke[i] == 0) answer++;
	}
	std::cout << answer << std::endl;
	return 0;
}