#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
	double xa,xb,ya,yb;
	scanf("%lf%lf%lf%lf", &xa, &ya, &xb, &yb);
	printf("%lf\n",(double)hypot(xa-xb,ya-yb) );
	return 0;
}
