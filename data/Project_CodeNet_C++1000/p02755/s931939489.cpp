#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
	int a, b; std::cin >> a >> b;
	for(int i = 1; i < 10001; ++i){
		int A = i * 8 / 100;
		int B = i * 10 / 100;
		if (a == A && b == B) {
			std::cout << i << std::endl;
			return 0;
		}
	}
	std::cout << -1 << std::endl;
	return 0;
}