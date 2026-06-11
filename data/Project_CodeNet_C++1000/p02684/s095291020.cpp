#include<iostream>
#include<vector>

int main() {
	int N;
	long long K;
	std::cin >> N >> K;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) std::cin >> A[i];

	std::vector<int> arrived;
	std::vector<int> order(N, -1);
	int now_place = 1;
	while (order[now_place - 1] == -1) {
		order[now_place - 1] = arrived.size();
		arrived.push_back(now_place);
		now_place = A[now_place - 1];
	}
	int length = arrived.size();
	int cycle = arrived.size() - order[now_place - 1];

	if (K < length) std::cout << arrived[K] << std::endl;
	else {
		K -= order[now_place - 1];
		K %= cycle;
		std::cout << arrived[order[now_place - 1] + K] << std::endl;
	}
	return 0;
}