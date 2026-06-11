#include <iostream>

int main(){

	int d;

	while(std::cin >> d){
		
		int squ;
		int sum_heights = 0;

		for(int i = 0; i < 600; i = i + d){
			sum_heights = sum_heights + (i * i);
		}

		squ = d * sum_heights;

		std::cout << squ << std::endl;
	}

	return 0;
}