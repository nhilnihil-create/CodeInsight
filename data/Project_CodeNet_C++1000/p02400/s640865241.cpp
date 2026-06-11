//============================================================================
// Name        : ku.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
using namespace std;
#include<cstdio>
#include<math.h>
int main(){
	double r,n,m;
	cin>>r;
	n=2*r*M_PI;
	m=r*r*M_PI;
	printf("%.5f %.5f",m,n);
	return 0;
}