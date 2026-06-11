#include<iostream>

int main()
{
	int H, W;
	while (1) {
		std::cin >> H >> W;
		if (H == 0 && W == 0)break;

		for (auto i = 0; i < H; i++) {
			for (auto j = 0; j < W; j++) {
				if ((i + j) % 2 == 0)
					std::cout << '#';
				else if ((i+ j) % 2 == 1)
					std::cout << '.';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}