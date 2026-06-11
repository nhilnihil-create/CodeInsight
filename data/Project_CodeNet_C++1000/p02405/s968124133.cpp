#include <iostream>
int main(){
	int H,W,x,y;
	while(true){
		std::cin >> H >> W;
		if(H == 0&&W == 0)break;
		for(int a = 0;a < H;a++){
			for(int b = 0;b < W;b++){
				x = a + b;
				y = x % 2;
				if(y == 0){
					std::cout <<"#";
				}else{
					std::cout <<".";
				}
			}
			std::cout <<std::endl;
		}
		std::cout <<std::endl;
	}
}