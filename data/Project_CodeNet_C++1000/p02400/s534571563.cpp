#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<iostream>


int main(){
	double r;
	std::cin >> r;
	double l, s;
	l = 2 * M_PI*r;
	s = M_PI * r*r;
	printf("%f %f\n", s,l);
}