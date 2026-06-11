#include <iostream>
int main() {
	int H[100], W[100];
	int i= 0, j, k, l;
	
	while (1) {
		std::cin >> H[i] >> W[i];
		if (H[i] == 0 && W[i] == 0) break;
		i++;
	}

	for (l = 0; l < i; l++) {
		for (k = 0; k < H[l]; k++) {
			for (j = 0; j < W[l]; j++) {
				std::cout << "#";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}