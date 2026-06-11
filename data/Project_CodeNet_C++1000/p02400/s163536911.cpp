#include<iostream>
#include<cstdio>
#define pi 3.141592653589
using namespace std;	

int main(){
	double r;
	cin >> r;
	double men = pi * r * r;
	double cir = pi * r * 2.0;
	printf("%f %f\n", men, cir);

	return 0;
}