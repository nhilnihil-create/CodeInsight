#include<iostream>

int main() {
	int N;
	std::cin >> N;
	N %= 10;
	if (N == 2 || N == 4 || N == 5 || N == 7 || N == 9) std::cout << "hon" << std::endl;
	else if (N == 0 || N == 1 || N == 6 || N == 8) std::cout << "pon" << std::endl;
	else std::cout << "bon" << std::endl;
	return 0;
}