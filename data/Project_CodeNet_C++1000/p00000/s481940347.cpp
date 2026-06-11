#include <iostream>

int main() {

	int i,j;
	int times;
	for (i = 1; i < 10; i++) {

		for (j = 1; j < 10; j++) {
			times = i * j;
			std::cout << i << "x" << j << "=" << times << std::endl;
		}
		
	}

	return 0;
}
