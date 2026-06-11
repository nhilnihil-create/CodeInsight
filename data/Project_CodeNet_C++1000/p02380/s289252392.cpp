#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	double a,b,c,cr,S,L,h;
	cin >> a >> b >> c;
	cr = c*3.1415926535/180;
	h = b*sin(cr);
	//S = a/2*h; //?????£?¢?
	S = a/2.0*b*sin(cr);
	//L = a+b+sqrt(pow(a-cos(cr)*b,2)+pow(h,2)); //?????£?¢?
	L = a+b+sqrt(a*a+b*b-2.0*a*b*cos(cr));

	printf("%f\n",S);
	printf("%f\n",L);
	printf("%f\n",h);
	//printf("%.16f\n",sin(cr));
	//printf("%.10f\n",cr);

	return 0; 
}