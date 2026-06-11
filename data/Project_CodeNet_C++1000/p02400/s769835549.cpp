#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	double r, s, e;
	
	cin >> r;
	
	s = r * r * 3.141592653589;
	e = r * 2 * 3.141592653589;
	printf("%f %f\n", s , e);
	
	return 0;

}