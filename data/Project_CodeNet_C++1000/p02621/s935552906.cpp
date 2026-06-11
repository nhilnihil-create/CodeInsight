#include<string.h>
#include<iostream>
#include<cmath>

int main() {
	int a = 0;
	int sum = 0;
	std::cin >> a;
	sum = a + std::pow(a, 2) + std::pow(a, 3);
	std::cout << sum;
	return 0;
}