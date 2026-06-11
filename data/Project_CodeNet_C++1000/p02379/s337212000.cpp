#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int main(){
	double x1, y1, x2, y2;
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	double d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	printf("%lf\n", d);
	return 0;
}