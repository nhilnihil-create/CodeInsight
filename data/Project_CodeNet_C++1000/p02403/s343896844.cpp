#include <iostream>
#include <cstdio>
int main(){
	int H,W,i,j;

	while(1){
		std::cin >> H >> W;
		if(H==0 && W==0)break;
		for(i=0;i<H;i++){
			for(j=0;j<W;j++){
				std::cout<<"#";
				if(j==W-1)
				std::cout<<"\n";					
				}
			if(i==H-1)
			std::cout<<"\n";	
			}
		
		}
	return 0;
}