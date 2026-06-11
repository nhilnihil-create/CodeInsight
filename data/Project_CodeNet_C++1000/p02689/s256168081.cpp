#include<iostream>
#include<vector>

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> height(N);
	for (int i = 0; i < N; i++) std::cin >> height[i];
	std::vector<bool> flag(N, true);

	for (int i = 0; i < M; i++) {
		int A, B;
		std::cin >> A >> B;
		if (height[A - 1] < height[B - 1]) flag[A - 1] = false;
		else if (height[A - 1] == height[B - 1]) {
			flag[A - 1] = false;
			flag[B - 1] = false;
		}
		else flag[B - 1] = false;
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		if (flag[i]) answer++;
	}
	std::cout << answer << std::endl;
	return 0;

}