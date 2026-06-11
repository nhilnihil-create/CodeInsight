#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
	long long A; std::cin >> A;
	std::string b; std::cin >> b;
	int B = (b[0] - '0') * 100 + (b[2] - '0') * 10 + (b[3] - '0');
	std::cout << A * B / 100 << std::endl;

	return 0;
}