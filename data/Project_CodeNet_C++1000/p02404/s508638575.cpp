#include <iostream>
#include <stdio.h>

int main()
{
	int H, W;
	while (std::cin >> H >> W, H || W)
	{
		for (int i = 0; i < H; i++)
		{
			if (i == 0 || i == H - 1)
			{
				for (int j = 0; j < W; j++)
				{
					std::cout << "#";
				}
			}
			else
			{
				for (int j = 0; j < W; j++)
				{
					if (j == 0 || j == W - 1)
					{
						std::cout << "#";
					}
					else
					{
						std::cout << ".";
					}
				}
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
	return 0;
}