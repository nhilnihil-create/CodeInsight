#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	double a,b,c,d;
	double X,Y;
	cin >> a >> b >> c >> d;
	X=(a-c)*(a-c);
	Y=(b-d)*(b-d);
	printf("%.7f\n",sqrt(X+Y));
	return 0;
}