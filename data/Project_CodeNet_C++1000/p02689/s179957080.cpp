#include<iostream>
#include<vector>

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> height(N);
	for (int i = 0; i < N; i++) std::cin >> height[i];
	std::vector<std::vector<int>> connection(N);
	for (int i = 0; i < M; i++) {
		int A, B;
		std::cin >> A >> B;
		connection[A - 1].push_back(B);
		connection[B - 1].push_back(A);
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		bool flag = true;
		for (int j : connection[i]) {
			if (height[j - 1] >= height[i]) flag = false;
		}
		if (flag) answer++;
	}
	std::cout << answer << std::endl;
	return 0;
}