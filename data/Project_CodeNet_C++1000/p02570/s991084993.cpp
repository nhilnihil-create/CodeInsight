#include <iostream>

int main(void) {
	int length, time, speed;
	std::cin >> length >> time >> speed;

	float estimated_time = length / (float)speed;

	if (estimated_time <= time) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}

	return 0;
}