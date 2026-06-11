#include<iostream>
int main(){
	while (true){
		int H, W, i, j;
		std::cin >> H >> W;
		if (H == 0 && W == 0){
			break;
		}
		else{
			for (i = 1; i <= H; i++){
				for (j = 1; j <= W; j++){
					std::cout << "#";
				}
				std::cout << "\n";
			}
		}
		std::cout << "\n";
	}
return 0;
}