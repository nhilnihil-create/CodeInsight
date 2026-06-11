#include "iostream"
#include "string"


int main()
{
	int H, W;

	while (true) {
		std::cin >> H >> W;

		if (W == 0 && H == 0)
			break;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (((j + i) % 2) == 0)
					std::cout << '#';
				else
					std::cout << '.';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}