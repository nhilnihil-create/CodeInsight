#include <iostream>

int main(int argc, char const* argv[])
{
	int h,w;
	std::cin >> h >> w;
	while (!(h==0&&h==w)) {
		for (int i = 0; i < h; i++) {
			for (int i = 0; i < w; i++) {
				std::cout << "#" ;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cin >> h >> w;
	}

	return 0;
}