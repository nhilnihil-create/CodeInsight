#include <iostream>
#include <cmath>
int main(int argc, char const *argv[])
{
	double x1,y1,x2,y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	double res = (double)sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	printf("%.7lf\n",res);
	return 0;
}