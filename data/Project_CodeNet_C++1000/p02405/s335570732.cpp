#include<iostream>
int main(){
	while(true){
		int H, W,a,b;
		std::cin >> H >> W;
		if (H == 0 && W == 0){
			break;
		}
		else{
			for (a = 1; a <= H; a++){
				for (b = 1; b <= W; b++){
					if ((a+b)%2==0){
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