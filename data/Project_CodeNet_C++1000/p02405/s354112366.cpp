#include <iostream>
#include <cstdio>
int main(){
	int H,W,i,j,a,b;

	while(1){
		std::cin >> H >> W;
		if(H==0 && W==0)break;
		for(i=0;i<H;i++){
			for(j=0;j<W;j++){
				a=i%2;
				b=j%2;
				if(a==0){
					if(b==0)
						std::cout<< "#";
					else
						std::cout<< ".";
					}
				if(a==1){
					if(b==0)
						std::cout<< ".";
					else
						std::cout<< "#";
					}	
				if(j==W-1)
				std::cout<<"\n";						
				}
			if(i==H-1)
			std::cout<<"\n";	
			}
		
		}
	return 0;
}