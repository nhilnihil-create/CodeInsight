#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int main() {
	int H[300];
	int W[300];
	int count;
	int i = 0;

	while (1) {
		std::cin >> H[i] >> W[i];
		if (H[i] == 0 && W[i] == 0) {
			count = i;
			break;
		}
		i++;
	}

	for (i = 0; i < count; i++) {
		for (int j = 0; j < H[i]; j++) {
			for (int k = 0; k < W[i]; k++) {
				std::cout << '#';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}

	return 0;
}