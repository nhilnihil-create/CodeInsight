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
	double X1,X2,Y1,Y2;
	double A=0;
	cin>>X1>>Y1>>X2>>Y2;

	A=sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));

	printf("%lf\n",A);
	return 0;
}