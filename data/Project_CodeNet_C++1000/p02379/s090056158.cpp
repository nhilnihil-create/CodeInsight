#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){

	double x1, x2, y1, y2;
	double r;

	cin >> x1 >> y1 >> x2 >> y2;

	r = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));


	printf("%.8lf\n" ,r);

 }