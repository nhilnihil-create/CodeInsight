#include <cstdio>
#include <cmath>

int main(){
	double x1, y1, x2, y2, d, dx, dy;
	scanf("%lf", &x1);
	scanf("%lf", &y1);
	scanf("%lf", &x2);
	scanf("%lf", &y2);
	dx = x1 - x2;
	dy = y1 - y2;
	d = sqrt(dx * dx + dy * dy);
	printf("%.5lf", d);
	return 0;
}