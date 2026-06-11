#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
	double a,b,r;
	scanf("%lf",&r);
	a=r*r*3.14159265359;
	b=(2*3.14159265359)*r;
	printf("%.5lf %.5lf\n",a,b);
	
	return 0;
}