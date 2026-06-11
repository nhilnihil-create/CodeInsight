#include <iostream>

int main(int argc, char const* argv[])
{
	int m,f,r;
	std::cin >> m>>f>>r;
	while (!(m == -1 && m == f && m == r)) {
		if (m == -1 || f == -1 || m + f < 30) {
			std::cout << "F";
		} else if (m + f >= 80) {
			std::cout << "A";
		} else if (m + f >= 65) {
			std::cout << "B";
		} else if (m + f >= 50) {
			std::cout << "C";
		} else {
			if (r >= 50) {
				std::cout << "C";
			} else {
				std::cout << "D";
			}
		}
		std::cin >> m>>f>>r;
		std::cout << std::endl;
	}
}