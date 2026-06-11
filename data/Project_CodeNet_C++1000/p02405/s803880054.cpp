#include <iostream>

int main(int argc, char const* argv[])
{
	int h, w;
	char output[3] = "#.";

	do {
		std::cin >> h >> w;
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				if (i % 2  == 0)
					std::cout << output[j % 2];
				else
					std::cout << output[(j + 1) % 2];
			}
			std::cout <<  std::endl;
		}

		if(h != 0 && w != 0)
			std::cout <<  std::endl;
	} while(h != 0 && w != 0);

	return 0;
}