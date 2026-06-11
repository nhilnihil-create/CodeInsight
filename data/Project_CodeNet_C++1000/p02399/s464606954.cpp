#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <iostream>

int main() {
	int a, b;
	std::cin >> a >> b;
	int d = a / b;
	int r = a % b;
	double aa, bb, f;
	aa = a;
	bb = b;
	f = aa / bb;
	std::cout << d << " " << r << " ";
	printf("%f", f);
	return 0;
}