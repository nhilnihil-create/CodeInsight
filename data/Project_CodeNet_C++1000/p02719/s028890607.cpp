#include<iostream>
#include<algorithm>
#include<cmath>

using sll = signed long long;

int main(){

	sll N, K;
	std::cin >> N >> K;

	const sll r{ N%K };

	std::cout << 
		std::min( r, std::abs( r - K ) ) 
		<< "\n";

	return 0;
}