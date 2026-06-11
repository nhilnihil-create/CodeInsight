#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int main(void){

	double x1,y1,x2,y2;
	double ans;

	cin>>x1>>y1>>x2>>y2;
	printf("%.8f\n",hypot(x1-x2,y1-y2));

	return 0;
}