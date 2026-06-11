#include <iostream>

int main(int argc, char const* argv[])
{
	int h, w;
	do {
		std::cin >> h >> w;
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
				std::cout << "#";
			std::cout <<  std::endl;
		}
        
		if(h != 0 && w != 0)
			std::cout <<  std::endl;
	} while(h != 0 && w != 0);

	return 0;
}