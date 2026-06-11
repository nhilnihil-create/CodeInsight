#include <iostream>
#include <stdio.h>

int main()
{
	int H, W;
	while (std::cin >> H >> W, H || W)
	{
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				std::cout << "#";
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
	return 0;
}