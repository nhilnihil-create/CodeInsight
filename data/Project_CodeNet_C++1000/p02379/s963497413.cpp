#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	double fX1, fX2, fY1, fY2;
	double fDis2 = 0, fDist = 0;
	cin >> fX1 >> fY1 >> fX2 >> fY2;
	fDis2 = pow((fX1 - fX2), 2) + pow((fY1 - fY2), 2);
	fDist = sqrt(fDis2);
	printf("%.8lf\n", fDist);


	//system("pause");
	return 0;
}