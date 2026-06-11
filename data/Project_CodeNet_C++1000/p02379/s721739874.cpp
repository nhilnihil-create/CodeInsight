#include <iostream>
#include<cmath>
#include<stdio.h>
using namespace std;


int main(){

	double x1, x2, y1, y2,L;
	cin >> x1 >> y1 >> x2 >> y2;



	L = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	printf("%.10lf", L);


	


	return 0;
}