#include <iostream>
#include <string>
#include <regex>

bool check(const std::string& buff) {
	return std::regex_match(buff, std::regex("(hi)+"));
}

void process() {
	auto buff = std::string{};
	std::getline(std::cin, buff);

	std::cout << (check(buff) ? "Yes" : "No") << std::endl;
}

int main() {
	process();
}