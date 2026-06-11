#include<iostream>

int main()
{
	const char SHARP = '#';
	int h, w;
	while(std::cin >> h >> w)
	{
		if(h == 0 && w == 0) break;

		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				std::cout << SHARP;
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
	
	return 0;
}