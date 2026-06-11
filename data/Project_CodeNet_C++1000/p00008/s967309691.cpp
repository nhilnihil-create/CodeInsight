#include<iostream>

int main(){
	int n;
	int count = 0;
	while (std::cin >> n){
		count = 0;
		if (n <= 36){
			for (int a = 0; a <= 9; ++a){
				for (int b = 0; b <= 9; ++b){
					for (int c = 0; c <= 9; ++c){
						if (a + b + c >= n - 9 && a + b + c <= n)++count;
					}
				}
			}
		}
		std::cout << count << std::endl;
	}
	return 0;
}