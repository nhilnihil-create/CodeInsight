#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int a,b,C;
	cin >> a >> b >> C;
	printf("%.4f\n%.4f\n%.4f\n"
			,a*b*sin((double)C/180*M_PI)/2
			,a+b+sqrt((double)pow(a,2)+pow(b,2)-2*a*b*cos((double)C/180*M_PI))
			,b*sin((double)C/180*M_PI));
	return 0;
}