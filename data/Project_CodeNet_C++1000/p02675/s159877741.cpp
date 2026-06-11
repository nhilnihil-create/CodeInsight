#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
int main()
{
	int N;
	std::cin >> N;
	switch (N % 10) {
	case 2:
	case 4:
	case 5:
	case 7:
	case 9:
		std::cout << "hon" << std::endl;
		break;
	case 3:
		std::cout << "bon" << std::endl;
		break;
	default:
		std::cout << "pon" << std::endl;
		break;
	}
	return 0;
}