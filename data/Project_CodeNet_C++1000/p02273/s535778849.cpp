#include <iostream>
#include <cmath>

void makeKochCurve(double x1, double y1, double x2, double y2, int depth)
{
	if (depth == 0) return;
	
	double length = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	double angle  = atan2(y2-y1, x2-x1);
	
	double xa = (2.0 * x1 + x2) / 3;
	double ya = (2.0 * y1 + y2) / 3;
	double xb = (x1 + x2) / 2 - sqrt(3) * length * sin(angle) / 6.0; 
	double yb = (y1 + y2) / 2 + sqrt(3) * length * cos(angle) / 6.0;
	double xc = (x1 + 2.0 * x2) / 3;
	double yc = (y1 + 2.0 * y2) / 3;

	makeKochCurve(x1, y1, xa, ya, depth-1);
	std::cout << xa << " " << ya << std::endl;
	makeKochCurve(xa, ya, xb, yb, depth-1);
	std::cout << xb << " " << yb << std::endl;
	makeKochCurve(xb, yb, xc, yc, depth-1);
	std::cout << xc << " " << yc << std::endl;
	makeKochCurve(xc, yc, x2, y2, depth-1);
}

int main()
{
	int n;
	std::cin >> n;
	
	std::cout << std::fixed;
	std::cout << 0.0 << " " << 0.0 << std::endl;
	makeKochCurve(0.0, 0.0, 100.0, 0.0, n);
	std::cout << 100.0 << " " << 0.0 << std::endl;
	
	return 0;
}


