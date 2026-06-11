#include<iostream>

int main(){
	int h,w;
	while(1){
		std::cin>>h>>w;
		if(h == 0 && w == 0)break;
		if(h > 0){
			for(int i = 0; i < w; ++i){
				std::cout<<"#";
			}
			std::cout<<std::endl;
		}
		for(int i = 0; i < h - 2; ++i){
			std::cout<<"#";
			for(int j = 0; j < w - 2; ++j){
				std::cout<<".";
			}
			if(w > 1)
			std::cout<<"#"<<std::endl;
		}
		if(h > 1){
			for(int i = 0; i < w; ++i){
				std::cout<<"#";
			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
	}
	return 0;
}