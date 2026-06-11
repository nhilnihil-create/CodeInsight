#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	double r, S, L, pi = 3.14159265358979;
	
	cin >> r;
	S = r*r*pi;
	L = 2*r*pi;
	
	printf("%f %f\n", S, L);
	
	return 0;
}