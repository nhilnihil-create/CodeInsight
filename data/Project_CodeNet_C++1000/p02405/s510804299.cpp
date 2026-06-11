#include <iostream>

int main(){
	int h;
	int w;

	while(true){
		std::cin>>h;
		std::cin>>w;
		if(h==0&&w==0){
			break;
		}
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				std::cout<<((i+j)%2==0?"#":".");
			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
	}
	return 0;
}