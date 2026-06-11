#include <iostream>
int main(){
	int H,W;
	while(true){
		std::cin >> H >> W;
		if(0 == H&&0 == W)break;
		for(int a = 0;a < H;a++){
			for(int b = 0;b < W;b++){
				std::cout << "#";
			}
			std::cout <<std::endl;
		}
		std::cout <<std::endl;	}
}