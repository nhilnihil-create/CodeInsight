#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	double a, b, C;
	
	scanf("%lf %lf %lf", &a, &b, &C);
	
	printf("%.7f\n", a * b * sin((M_PI * C / 180)) / 2);
	printf("%.7f\n", a + b + sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos((M_PI * C / 180))));
	printf("%.7f\n", b * sin((M_PI * C / 180)));

	return 0;
}

