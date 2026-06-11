#include <iostream>

int main(void)
{
	int H, W, chip;
	while (true)
	{
		std::cin >> H >> W;
		if (H == 0 && W == 0) break;
		for (int i = 0; i < H; i++) {
			chip = i % 2;
			for (int i = chip; i < W + chip; i++) {
				std::cout << (i % 2 ? '.' : '#');
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}