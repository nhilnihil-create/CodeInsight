#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

int main(){
	double x1,x2,y1,y2,x,y,n;
	cin >> x1 >> y1 >> x2 >> y2;
	x=x2-x1;
	y=y2-y1;
	n=sqrt((double)pow(x,2.0)+(double)pow(y,2.0));
	printf("%.5f\n",n);
}