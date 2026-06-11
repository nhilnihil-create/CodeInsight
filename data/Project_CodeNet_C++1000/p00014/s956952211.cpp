#include<iostream>
#include<cmath>

int main(){
	int d;
	while(std::cin >> d){
		int S=0;
		int d3 = d*d*d;
		for(int i=1; i<600/d; ++i){
			S += d3*i*i;
		}
		std::cout << S << std::endl;
	}
	return 0;
	
}