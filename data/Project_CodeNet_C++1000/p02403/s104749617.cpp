#include<iostream>

int main(void){
	int H, W;
	
	while(1){
		std::cin >> H >> W;
		
		if (H == 0 && W ==0) break;
		
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W;  j++) {
				std::cout << '#';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	
	return 0;
}