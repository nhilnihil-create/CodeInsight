#include <iostream>
#include <math.h>

int main(void) {
	long int in;
	long int i = 2;
	std::cin >> in;
	std::cout << in << ":";
	while (in != 1) {
		if (i > sqrt(in)) {
			std::cout << " " << in;
			break;
		} else if (in % i != 0) {
			i += 1;
		} else {
			in = in / i;
			std::cout << " " << i; 
			i = 2;
		}
	}
	std::cout << std::endl;
}