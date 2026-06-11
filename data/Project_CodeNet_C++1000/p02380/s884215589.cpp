#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	double pi,a,b,C,S,L,h,c;
	cin >> a>>b >>C ;
	c = C*3.1415926535*2.0/360.0;
	S =1.0/2.0*sin(c)*a*b;
	L =sqrt(a*a+b*b-2.0*a*b*cos(c))+a+b;
	h =b*sin(c);
	printf("%.8f %.8f %.8f\n",S,L,h);
	return 0;
}