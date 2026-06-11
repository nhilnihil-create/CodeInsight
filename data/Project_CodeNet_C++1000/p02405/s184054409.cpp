#include<iostream>

int main(void){
	int H, W;
	
	while(1){
		std::cin >> H >> W;
		
		if (H == 0 && W ==0) break;
		
		for (int i = 1; i <= H; i++) {
			if (i % 2 == 1){
				for (int j = 1; j <= W;  j++) {
					if (j % 2 == 1) std::cout << '#';
					else std::cout << '.';
				}
			}
			else {
				for (int j = 1; j <= W;  j++) {
					if (j % 2 == 1) std::cout << '.';
					else std::cout << '#';
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	
	return 0;
}