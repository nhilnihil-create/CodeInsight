#include<cstdio>
#include<cmath>
#include<limits>
int main() {
	double x1, x2, y1, y2;
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	printf("%f", std::sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)));
	return 0;
}
