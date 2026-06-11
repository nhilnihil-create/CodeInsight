#include <iostream>
#include <cmath>
#define N 120
typedef long long int ll;

int main(void){
	long x;
	int a = 0, b = 0;
	std::cin >> x;
	for(a = 0; a < N; a++){
		for(b = 0; b < N; b++){
			ll a5 = pow(a, 5);
			ll b5 = pow(b, 5);
			if(a5 - b5 == x){
				std::cout << a << " " << b << std::endl;
				return 0;
			}
			else if(a5 + b5 == x){
				std::cout << a << " " << b*(-1) << std::endl;
				return 0;
			}
		}
	}
}
