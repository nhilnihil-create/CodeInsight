#include <iostream>

void call(int n){
	int i = 1;
	int x = i;

	while(++i <= n){
		x = i;
		if(x % 3 == 0){
			std::cout << " " << i;
			continue;
		}
		while(x){
			if(x % 10 == 3){
				std::cout << " " << i;
				break;
			}
			x /= 10;
		}
	}

	std::cout << std::endl;
	return;
}

int main(int argc, char **argv){
	int n = 0;

	std::cin >> n;
	call(n);
	
	return 0;
}