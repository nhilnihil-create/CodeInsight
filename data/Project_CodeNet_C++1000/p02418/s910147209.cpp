#include <iostream>
#include <string>
#include <deque>

int main() {
	std::string str1, str2;
	std::cin >> str1 >> str2;
	str1 += str1;
	
	if (str1.find(str2) != std::string::npos)
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

	return 0;
}