#include <iostream>

int main(int argc, char **argv){
	int h = 0;
	int w = 0;

	while(std::cin >> h >> w, (h != 0 || w != 0)){
		for(int y = 0; y < h; y++){
			for(int x = 0; x < w; x++){
				std::cout << "#";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}