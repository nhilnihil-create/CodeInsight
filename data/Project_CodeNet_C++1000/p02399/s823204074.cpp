#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	int d,r,x,y;
	double f,a,b;
	cin >> x >> y;
	d = x / y;
	a = x;
	b = y;
	r = x%y;
	f = a / b;
	cout << d << " " << r << " ";
		printf("%.8f\n",f);
	return 0;
}