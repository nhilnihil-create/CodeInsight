#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	int N; std::cin >> N;
	std::string s; std::cin >> s;
	int count{ 0 };
	for (auto i = 0; i < N - 2; ++i) {
		if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
			++count;
	}
	std::cout << count << std::endl;

	return 0;
}
