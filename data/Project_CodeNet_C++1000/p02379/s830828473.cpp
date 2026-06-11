#include <iostream>
#include <stdio.h>

double sqrt(double number, const int& SIGNIFICANT_DIGITS);

int main(){
	double x1, x2, y1, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	printf("%0.5f\n", sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2), 10));
	return 0;
}

double sqrt(double number, const int& SIGNIFICANT_DIGITS){
	double result = 0;
	double digitsOffset = 1;

	for (int i = 0; i < SIGNIFICANT_DIGITS + 1; i++){
		while (number >= (result + digitsOffset) * (result + digitsOffset)){
			result += digitsOffset;
		}
		digitsOffset /= 10;
	}
	return result;
}
