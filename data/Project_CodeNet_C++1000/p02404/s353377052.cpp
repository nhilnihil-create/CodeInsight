#include "iostream"
#include "string"


int main()
{
	int W, H;
	char rect[300][300];

	while (true) {
		std::cin >> H >> W;

		if (W == 0 && H == 0)
			break;

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				rect[i][j] = '.';

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				rect[0][j] = '#';
				rect[i][0] = '#';
				rect[H-1][j] = '#';
				rect[i][W-1] = '#';
			}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				std::cout << rect[i][j];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}