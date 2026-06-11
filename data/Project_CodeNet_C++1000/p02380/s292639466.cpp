//============================================================================
// Name        : AOJ.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int a,b,c;
	cin>>a>>b>>c;

	double S=0,L=0,h=0,d;

	d=(acos(-1.0)*c)/180.0;
	S=a*b*sin(d)/2.0;
	L=a+b+sqrt(a*a+b*b-2*a*b*cos(d));
	h=b*sin(d);

	printf("%lf\n%lf\n%lf\n",S,L,h);

	return 0;
}