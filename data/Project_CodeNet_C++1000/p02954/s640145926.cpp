#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#define intt long long

int main() {
	std::string S; std::cin >> S;
	int N = S.size();
	std::vector<int> COUNT(N);
	for (int i = 0; i < N; ++i) {
		int count1 = 0;
		if (S[i] == 'R') {
			int j;
			for (j = i; j < N; ++j) {
				++count1;
				if (S[j] == 'L') {
					i = j;
					--count1;
					break;
				}
			}
			if (count1 % 2 == 1) {
				COUNT[j] += count1 / 2;
				COUNT[j - 1] += (count1 / 2) + 1;
			}
			else {
				COUNT[j] += count1 / 2;
				COUNT[j - 1] += count1 / 2;
			}
		}
	}
	std::reverse(S.begin(), S.end());
	std::reverse(COUNT.begin(), COUNT.end());
	for (int i = 0; i < N; ++i) {
		if (S[i] == 'L') {
			int j;
			int count2 = 1;
			for (j = i; j < N; ++j) {
				if (S[j] == 'R') {
					--count2;
					i = j;
					break;
				}
				else
					++count2;
			}
			if (count2 % 2 == 1) {
				COUNT[j] += count2 / 2;
				COUNT[j - 1] += (count2 / 2) + 1;
			}
			else {
				COUNT[j] += count2 / 2;
				COUNT[j - 1] += count2 / 2;
			}
		}
	}
	std::reverse(S.begin(), S.end());
	std::reverse(COUNT.begin(), COUNT.end());

	for (int i = 0; i < N; ++i) {
		if (i > 0)
			std::cout << " ";
		std::cout << COUNT[i];
	}
	std::cout << std::endl;

	return 0;
}