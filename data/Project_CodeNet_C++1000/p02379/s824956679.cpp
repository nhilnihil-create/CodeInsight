#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

double a,b,c,d;
int main(){
	cin >> a >> b >> c >> d;
	double e = sqrt((a-c)*(a-c)+(b-d)*(b-d));
	printf("%.6f\n",e);
}
