#include <iostream>
#include <stdio.h>
#define pi    3.141592653589
using namespace std;

int main(){
	double r, S, l;

	cin>>r;
	S = r * r * pi;
	l = 2 * r * pi;

	printf("%.6lf %.6lf\n", S, l);

	return 0;
}