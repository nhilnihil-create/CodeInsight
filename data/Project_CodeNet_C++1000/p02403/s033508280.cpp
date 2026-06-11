#include<iostream>
#include<stdio.h>

int main()
{
	int h, w;
	int i, j;
	std::cin >> h;
	std::cin >> w;
	while (h != 0 || w != 0){
		for (i = 0; i < h; i++){
			for (j = 0; j < w; j++){
				std::cout << "#";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		std::cin >> h;
		std::cin >> w;
	}
	return 0;
}