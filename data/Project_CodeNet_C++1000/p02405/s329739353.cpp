
#include <iostream>

int main() {
	int h, w;
	int i, j;
	
	while (1)
	{
		std::cin >> h >> w;
		if (h == 0 || w == 0) break;

		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				if(i%2 == 0){
					if (j%2 == 0) std::cout << "#";
					else          std::cout << ".";
				}
				else
				{
					if (j%2 == 0) std::cout << ".";
					else          std::cout << "#";
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}