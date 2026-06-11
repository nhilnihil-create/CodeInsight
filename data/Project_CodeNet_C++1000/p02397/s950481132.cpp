#include<iostream>

int main(){
	
	int x,y,k;
	
	while (1){
		
		std::cin >>x>>y;
		if (x==0 && y ==0)break;
		else if (x>y) k=x, x=y, y=k;
		std::cout << x <<" "<< y <<"\n";		
		
	}
	
	return 0;
	
}