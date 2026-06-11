#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>

const int MAX = 1001001001;

int main() {

	int N, M, X;
	std::cin >> N >> M >> X;
	std::vector<int> C(N);
	std::vector<std::vector<int>> A(N, std::vector<int> (M));
	for (int i = 0; i < N; i++) {
		std::cin >> C[i];
		for (int j = 0; j < M; j++) {
			std::cin >> A[i][j];
		}
	}

	int answer = MAX;
	for (int i = 0; i < 1 << N; i++) {
		int cost = 0;
		std::vector<int> skill(M);
		for (int j = 0; j < N; j++) {
			if (i >> j & 1) {
				cost += C[j];
				for (int k = 0; k < M; k++) skill[k] += A[j][k];
			}
		}
		int count_error = 0;
		for (int j = 0; j < M; j++) {
			if (skill[j] < X) count_error = 1;
		}
		if (count_error == 0) answer = std::min(cost, answer);
	}

	if (answer == MAX) std::cout << -1 << std::endl;
	else std::cout << answer << std::endl;
	return 0;
}