#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	double x1, y1, x2, y2, dis;
	cin>>x1>>y1>>x2>>y2;

	dis = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));

	printf("%.8lf\n", dis);

	return 0;
}