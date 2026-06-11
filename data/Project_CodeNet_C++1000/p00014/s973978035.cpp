#include<iostream>

int main() {
	int d;
	while (std::cin >> d) {
		int s = 0;
		for (int i = 1; i*d < 600; i++) {
			s += (i*d) * (i*d) * d;
		}
		std::cout << s << std::endl;
	}
	return 0;
}