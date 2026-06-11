#include <iostream>
#include <cstdio>
#include <cmath> 
using namespace std;

int main()
{
    double a,b,sinB,c,C,S,L,h;
	cin>>a>>b>>C;
	S=0.5*a*b*sin(C*M_PI/180);
	c=sqrt(pow(a,2.0)+pow(b,2.0)-2*a*b*cos(C*M_PI/180));
	L=a+b+c;
	sinB=(2*S)/(a*c);
	h=c*sinB;
	
	printf("%10f\n%10f\n%10f\n",S,L,h);
    return 0;
}