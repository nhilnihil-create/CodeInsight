#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
double rad(int p){
	double rad=(acos(-1.0)*p)/180.0;
	return rad;
}

int main()
{
	int a,b,C;
	double S,L,h;
	cin>>a>>b>>C;
	S=0.5*a*b*sin(rad(C));
	L=a+b+(sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(rad(C))));
	h=b*sin(rad(C));

	printf("%lf %lf %lf\n",S,L,h);
	return 0;
}