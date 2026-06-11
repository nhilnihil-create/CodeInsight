#include <iostream>
#include <stdio.h>
int main(){
	int a,b,d,r;
	std::cin >> a >> b;
	d = a / b;
	r = a % b;
	double f;
	f = 1.00000 * a / b;
	std::cout << d <<" "<< r <<" ";
	printf("%.5lf", f);
return 0;
}