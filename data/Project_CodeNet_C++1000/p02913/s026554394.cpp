#include <iostream>
#include <vector>

std::vector<int> z_algorithm(const std::string& S) {
	const int N = S.size();
	std::vector<int> Z(N, -1);
	Z[0] = N;
	int matched_length = 0;
	for (int i = 1; i < N; i++) {
		int j = i + matched_length;
		while (j < N && S[j - i] == S[j]) j++;
		Z[i] = matched_length = j - i;
		if (Z[i] == 0) continue;
		for (j = i + 1; j < i + Z[i] && Z[j - i] < i + Z[i] - j; j++) Z[j] = Z[j - i];
		matched_length = i + Z[i] - j;
		i = j - 1;
	}
	return Z;
}

int main() {
	int N;
	std::string S;
	std::cin >> N >> S;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		std::vector<int> Z = z_algorithm(S.substr(i));
		for (int j = 0; j < N - i; j++) ans = std::max(ans, std::min(j, Z[j]));
	}
	std::cout << ans << std::endl;
}