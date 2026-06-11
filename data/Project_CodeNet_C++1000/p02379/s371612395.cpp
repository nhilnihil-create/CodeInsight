#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
	double x1, x2, y1, y2,a,b;
	cin >> x1 >> y1 >> x2 >> y2;
	a = pow(x2 - x1, 2) + pow(y2 - y1, 2);
	b = sqrt(a);
	printf("%f\n", b);

	return 0;
}
