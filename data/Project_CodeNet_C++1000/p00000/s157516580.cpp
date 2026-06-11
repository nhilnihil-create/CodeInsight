#include <iostream>


int main()
{
	for(int i = 1; i < 10; i++) {
		for(int k = 1; k < 10; k++) {
			int l = i * k;
			std::cout << i << "x" << k << "=" << l<< std::endl;
		}
	}
	return 0;
}