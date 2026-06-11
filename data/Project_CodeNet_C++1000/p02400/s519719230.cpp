#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

const static double pi = 4*atan(1.0);
int main(){
	double r;
	cin >> r;
	printf("%.7f\n",r*r*pi);
	printf("%.7f\n",2*pi*r);
	return 0;
}