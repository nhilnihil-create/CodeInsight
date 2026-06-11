#include <iostream>

int main(){
	int H,W;
	while(1){
		std::cin >> H >> W;
		
		if(H == 0 && W ==0){break;}

		//??????????¨?
		for(int a=0;a<W;a++){
			std::cout << "#";
		}
		std::cout << std::endl;
		//??????????¨?

		//??????
		for(int i=1;i<H-1;i++){
			std::cout << "#";
		for(int j=1;j<W-1;j++){
			std::cout << ".";
		}
		std::cout << "#" << std::endl;
		}

		for(int b=0;b<W;b++){
		std::cout << "#";
		}
		std::cout << std::endl << std::endl;
	}
}