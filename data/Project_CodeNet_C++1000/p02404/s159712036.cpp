#include <iostream>

int main()
{
	int H, W;
	std::cin >> H >> W;

	while (H != 0 || W != 0) {
		for (int i = 0; i < H; i++) {
			if (i == 0 || i == H - 1) {
				for (int j = 0; j < W; j++) {
					std::cout << "#";
				}
			}
			else {
				for (int j = 0; j < W; j++) {
					if (j == 0 || j == W - 1) {
						std::cout << "#";
					}
					else {
						std::cout << ".";
					}
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cin >> H >> W;
	}
}