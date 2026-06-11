#include "iostream"
#include "math.h"


int main()
{
	int n;
	double x[1000], y[1000];
	double p1 = 0, p2 = 0, p3 = 0, pI = -1, tempI;
	std::cin >> n;
	for (int i = 0; i < n; i++) 
		std::cin >> x[i];
	for (int i = 0; i < n; i++)
		std::cin >> y[i];
	for (int i = 0; i < n; i++) {
		p1 += fabs(x[i] - y[i]);
		p2 += pow(x[i] - y[i], 2);
		p3 += pow(fabs(x[i] - y[i]), 3);
		tempI = fabs(x[i] - y[i]);
		if (tempI > pI)
			pI = tempI;
	}
	p2 = sqrt(p2);
	p3 = cbrt(p3);
	std::cout << p1 << std::fixed << std::endl << p2 << std::fixed
		<< std::endl << p3 << std::fixed << std::endl << pI << std::fixed << std::endl;
    return 0;
}