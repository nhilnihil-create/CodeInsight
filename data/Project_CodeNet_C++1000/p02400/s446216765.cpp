#include <iostream>
#include <stdio.h>
using namespace std;
static const double PI = 3.141592653589;

int main(void){
	double r,menseki,ensyu;
	cin >> r;
	menseki = PI * r * r;
	ensyu = 2 * PI * r;

	printf("%f %f\n",menseki,ensyu);
}