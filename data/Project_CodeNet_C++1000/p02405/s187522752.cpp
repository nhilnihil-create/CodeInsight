#include<iostream>

int main()
{
	const char SHARP = '#';
	const char DOT = '.';
	int h, w;
	while(std::cin >> h >> w)
	{
		if(h == 0 && w == 0) break;
		for(int y=0; y<h; y++){
			if(y % 2 == 1){
				for(int x=0; x<w; x++){
					if(x % 2 == 1){
						std::cout << SHARP;
					} else {
						std::cout << DOT;
					}
				}
				std::cout << '\n';
			} else {
				for(int x=0; x<w; x++){
					if(x % 2 == 1){
						std::cout << DOT;
					} else {
						std::cout << SHARP;
					}
				}
				std::cout << '\n';
			}
		}
		std::cout << '\n';
	}
	return 0;
}