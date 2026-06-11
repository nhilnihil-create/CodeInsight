#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int main(void)
{
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	printf("%f\n",sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
}