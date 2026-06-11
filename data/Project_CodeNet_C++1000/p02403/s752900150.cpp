#include <iostream>

int main(int argc, char** argv)
{
	while (true)
	{
		int height, width;
		std::cin >> height >> width;

		if (height == 0 && width == 0)
		{
			break;
		}

		for (int h = 0; h < height; ++h)
		{
			for (int w = 0; w < width; ++w)
			{
				std::cout << "#";
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;
	}
}
