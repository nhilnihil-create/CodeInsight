#include <iostream>

int main(void)
{
	int H, W;
	while (true)
	{
		std::cin >> H >> W;
		if (H == 0 && W == 0) break;
		for (int i = 0; i < W; i++) {
			std::cout << '#';
		}
		std::cout << std::endl;
		for (int i = 1; i < H - 1; i++) {
			std::cout << '#';
			for (int i = 1; i < W - 1; i++) {
				std::cout << '.';
			}
			std::cout << '#';
			std::cout << std::endl;
		}
		for (int i = 0; i < W; i++) {
			std::cout << '#';
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	return 0;
}