#include <iostream>
int main(){
	int a1,a2,a3,a4;
	int a[4],b[4],c;
	while(std::cin>>a1>>a2>>a3>>a4){
		int o=0,i=0;
			for(int v=0;v<4;v++){
			std::cin>>b[v];
		}
		
			for(int p=0;p<4;p++){
				if(a1==b[p]){
					if(0==p){
						o++;
					}else{
						i++;
					}
					}	if(a2==b[p]){
					if(1==p){
						o++;
					}else{
						i++;
					}
				}
						if(a3==b[p]){
					if(2==p){
						o++;
					}else{
						i++;
					}
					}	if(a4==b[p]){
					if(3==p){
						o++;
					}else{
						i++;
					}
				}
			}
		
	

		std::cout<<o<<" "<<i<<std::endl;
	}
	return 0;


}