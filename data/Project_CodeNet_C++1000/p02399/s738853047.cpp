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
int main(){
	int a,b,x,y;
	double z;
	cin>>a>>b;
	x=a/b;
	y=a%b;
	z=1.00000000*a/b;
	cout<<x<<" "<<y<<" ";
	printf("%.8f\n",z);

}