#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	double r;
	cin >> r;
	printf("%.8lf %.8lf\n",r*r*4*atan(1),2*r*4*atan(1));
	return 0;
}