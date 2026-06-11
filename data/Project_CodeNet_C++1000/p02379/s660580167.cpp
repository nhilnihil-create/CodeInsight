#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	double x1,y1,x2,y2,r,r2;
	cin >> x1 >>y1 >> x2 >> y2;
	r2 = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	r = sqrt(r2);
	printf("%.8f\n",r);
	return 0;
}