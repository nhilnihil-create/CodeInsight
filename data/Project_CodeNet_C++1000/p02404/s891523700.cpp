#include<iostream>
int main(){
	while(true){
		int H, W,a,b,c,d;
		std::cin >> H >> W;
		if (H == 0 && W == 0){
			break;
		}
		else{
			for (a = 1; a <= H; a++){
				for (b = 1; b <= W; b++){
					if (a == 1 || b == 1||a==H||b==W){
						std::cout << "#";
					}
					else{
						std::cout << ".";
					}
				}
				std::cout << "\n";
			}
		}
		std::cout << "\n";
	}
}