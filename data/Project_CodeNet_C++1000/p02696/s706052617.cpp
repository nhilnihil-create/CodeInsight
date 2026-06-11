#include <cmath>
#include <iostream>

typedef long long int ll;

int main(void){
	ll a, b, n, res = 0, x;
	std::cin >> a >> b >> n;
	x = std::min(b-1, n);
	res = floor(a * x / b);

	std::cout << res << std::endl;
	return 0;
}
