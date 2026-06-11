#include<cstdio>
#include<cmath>
int main() {
	double a, b, C;
	scanf("%lf%lf%lf", &a, &b, &C);
	C = C*3.14159265 / 180;
	printf("%f\n%f\n%f\n", 0.5*a*b*std::sin(C), a+b+std::sqrt(a*a + b*b - 2 * a*b*std::cos(C)), b*std::sin(C));
	return 0;
}
