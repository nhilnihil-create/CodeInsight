#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

int main() {
	std::string s; std::cin >> s;
	int counta = 0;
	for (int i = 0; i < s.size(); ++i) {
		++counta;
		if (s[i] == s[i + 1]) {
			++counta;
			i += 2;
			if (i >= s.size())
				--counta;
		}
	}
	int countb = 0;
	if (s[0] == s[1]) {
		countb = 1;
		for (int i = 2; i < s.size(); ++i) {
			++countb;
			if (s[i] == s[i + 1]) {
				++countb;
				i += 2;
				if (i >= s.size())
					--countb;
			}
		}
	}
	std::cout << std::max(counta, countb) << std::endl;

	return 0;
}
