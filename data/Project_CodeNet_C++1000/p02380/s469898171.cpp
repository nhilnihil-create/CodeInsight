#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#define PI 3.1415926535897932
using namespace std;

int main(){
	int a,b,C;
	double S,h,L;
	double X;
	cin >>a>>b>>C;
	X=(double)C*PI/180.0;
	h=b*sin(X);
	S=h*a/2;
	L=sqrt((double)((a*a)+(b*b)-2*a*b*cos(X)));
	L+=(a+b);
	printf("%.6f\n",S);
	printf("%.6f\n",L);
	printf("%.6f\n",h);
	return 0;
}