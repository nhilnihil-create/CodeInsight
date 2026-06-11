#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
	double x1, x2, y1, y2, p1 , p2 , x ;
	cin >> x1 >> y1 >> x2 >> y2;
	p1 = x2 - x1;
	p2 = y2 - y1;
	x = p1*p1 + p2*p2;
	x = sqrt(x);
	printf("%.8lf\n ", x);
	return 0;
}