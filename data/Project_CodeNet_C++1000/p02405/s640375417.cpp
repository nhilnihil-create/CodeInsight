#include<iostream>
int main(){
	int h,w;
	while(1){
		std::cin>>h>>w;
		if(w == 0 && h == 0) break;
		for(int i = 0,k = 0; i < h; k = ++i){
			for(int j = 0; j < w; ++j){
				if(k % 2 == 0)
					std::cout<<"#";
				else
					std::cout<<".";
				++k;
			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
	}
	return 0;
}