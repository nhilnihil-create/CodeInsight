#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	const double pi = 3.141592653589;
	double r;
	scanf("%lf", &r);
	printf("%f %f\n", pi*r*r, 2 * pi*r);
}