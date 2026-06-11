#include<iostream>
#include<stdio.h>

int main(){
	int  a, b;
	int  d, r;
	double f;
	std::cin >> a;
	std::cin >> b;
	d = a / b;
	r = a%b;
	double x = a;
	double y = b;
	f = x / y;
	std::cout << d << " ";
	std::cout << r << " ";
	printf("%f\n",f);
}