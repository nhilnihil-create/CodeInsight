#include<iostream>
const char SHARP = '#';
const char DOT = '.';

int main()
{
	int h, w;
	while(std::cin >> h >> w) {
		if(h == 0 && w == 0) break;
		for(int i=0; i<h; i++){
			if(i == 0 || i == h-1){
				for(int j=0; j<w; j++){
					std::cout << SHARP;
				}
				std::cout << '\n';
			} else {
				for(int j=0; j<w; j++){
					if(j == 0 || j == w-1){
						std::cout << SHARP;
					} else {
						std::cout << DOT;
					}
				}
				std::cout << '\n';
			}
		}
	std::cout << '\n';
	}
	return 0;
}

			