#include<iostream>
#include<algorithm>
#include <array>
int main(void){
	int x,y,temp;

		while(1){
		std::cin >>x>>y;
		if (x == 0&&y == 0){
			break;
		}
		if (x > y){
			std::swap(x, y);
		}
		std::cout << x <<" "<< y << std::endl;
	}
	return 0;
}