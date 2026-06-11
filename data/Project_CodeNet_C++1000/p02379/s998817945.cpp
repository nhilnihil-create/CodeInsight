#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

int main(void)
{
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2; 
	
	double x = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	
	double y = sqrt(x);
	
	printf("%.4f\n", y);
	//cout << y << endl;
	
	return 0;
}