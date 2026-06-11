#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>

std::vector<std::pair<long long, long long>> prime_factorize(long long N) {
	std::vector<std::pair<long long, long long>> result;

	for (long long i = 2; i * i <= N; i++) {
		if (N % i != 0) continue;

		long long power = 0;
		while (N % i == 0) {
			N /= i;
			power++;
		}

		result.push_back({ i,power });
	}

	if (N != 1) result .push_back({ N,1 });

	return result;
}

int main() {
	long long N;
	std::cin >> N;
	
	if (N == 1) {
		std::cout << 0 << std::endl;
		return 0;
	}
	if (N == 2 || N == 3) {
		std::cout << 1 << std::endl;
		return 0;
	}

	auto factor_list = prime_factorize(N);
	long long answer = 0;
	for (auto factor : factor_list) {
		long long count = 1;
		while (factor.second-count >= 0) {
			factor.second -= count;
			count++;
		}
		count--;
		answer += count;
	}

	std::cout << answer << std::endl;
	return 0;
}