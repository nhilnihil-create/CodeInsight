#include<iostream>
#include<cstdio>

#define _USE_MATH_DEFINES
#include<cmath>

using namespace std;

int main(void){
	double r;
	double pai = 3.141592653589;
	
	cin >> r;
	
	printf("%.6f %.6f\n", r*r*pai, 2*r*pai);
	
	return 0;
}