#include <iostream>
int main(){
	int H,W;
	while(true){
		std::cin >> H >>W;
		if(H == 0&&W == 0)break;
		for(int a = 0;a < H;a++){
			for(int b = 0;b < W;b++){
				if(a == 0||a == H - 1||b == 0||b == W - 1){
					std::cout << "#";
				}else{
					std::cout << ".";
				}
			}
			std::cout << std::endl;
		}
		std::cout <<std::endl;
	}
}