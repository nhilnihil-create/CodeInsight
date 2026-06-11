#include <iostream>
typedef long long int ll;
typedef long double ld;

int main(void){
	int K, i = 0;
	int a[1000000];
	std::cin >> K;
	a[0] = 7 % K;
	if(a[0] == 0){
		std::cout << i+1 << std::endl;
		return 0;
	}
	for(i = 1; i <= K; i++){
		a[i] = (a[i-1]*10 + 7) % K;
		if(a[i] == 0){
			std::cout << i+1 << std::endl;
			return 0;
		}
	}
	std::cout << -1 << std::endl;

	return 0;
}
