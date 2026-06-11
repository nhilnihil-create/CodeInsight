#include<iostream>
#include<string>

int main() {
	std::string num;
	std::string::iterator ptr;
	std::cin >> num;
	int all = 0;
	int tmp;

	for (ptr = num.begin(); ptr != num.end(); ptr++) {
		char& c = *ptr;
		tmp = (int)(c - '0');
		all += tmp;
	}

	if (all % 9 == 0) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
	return 0;

}