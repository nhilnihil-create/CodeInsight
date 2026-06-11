#include <cmath>
#include <iostream>
typedef long long int ll;
typedef long double ld;

int main(void){
	ll A, res;
	float b;
	std::cin >> A >> b;
	float B = std::round(b * 100);
	res = A * B / 100;
	
	std::cout << res << std::endl;
	return 0;
}
// WA, AC with answer
