#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
	double x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	double d1=(x1-x2);
	double d2=(y1-y2);
	printf("%lf\n",sqrt(d1*d1+d2*d2));
	
	return 0;
}