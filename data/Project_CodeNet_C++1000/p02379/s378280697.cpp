#include<iostream>
#include<cstdio>
#include<cmath>

int main(){

	double x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	printf("%.8f\n", std::sqrt(std::abs(x1 - x2)*std::abs(x1 - x2) + std::abs(y1 - y2)*std::abs(y1 - y2)));

	return 0;
}