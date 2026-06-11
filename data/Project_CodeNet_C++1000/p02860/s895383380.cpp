#include <iostream>
#include <string>

int main() {
	std::string s;
	int n;
	std::cin >> n >> s;
	if (n % 2 != 0)
		std::cout << "No";
	else {
		std::string k(s, 0, n / 2);
		std::string m(s, n / 2, n / 2);
		if (k == m) {
			std::cout << "Yes";
		}
		else
			std::cout << "No";
	}
	return 0;
}