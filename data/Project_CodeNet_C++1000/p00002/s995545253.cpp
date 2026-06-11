#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <cmath>

int main(){
	int i;
	int j;
	while (std::cin >> i >> j){
		int t = i+j;
		int y;
		for ( y = 1; t / static_cast<int>(pow(10, y)) > 0; ++y){}
		std::cout << y << std::endl;
	}

	return 0;
}