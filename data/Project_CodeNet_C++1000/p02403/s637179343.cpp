# include <iostream>
# include <iomanip>

int main() {
	int H, W;
   	while(true){
   		std::cin >> H >> W;
   		if(H == 0 && W == 0)
   			break;
   		for(int y = 0; y < H; y++){
   			for(int x = 0; x < W; x++){
   				std::cout << "#" ;
   			}
   			std::cout << std::endl;
   		}
   		std::cout << std::endl;
   	}
   	return 0;
}