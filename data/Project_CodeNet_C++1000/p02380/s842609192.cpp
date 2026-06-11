#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main(){
	double a,b,c,d,s,L,h;

	cin>>a>>b>>c;

	s=0.5*a*b*sin(c*M_PI/180);
	printf("%.10f\n",s);
	h=2*s/a;
	

	d=sqrt(a*a+b*b-2*a*b*cos(c*M_PI/180));

		L=a+b+d;
	printf("%.10f\n",L);		
	printf("%.10f\n",h);

}