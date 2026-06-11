#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int n;
	double x[100] = {0}, y[100] = {0};
	double p_1 = 0, p_2 = 0, p_3 = 0, p_inf = -1;

	scanf("%d", &n);

	for(int i = 0;i < n;i++) {
		scanf("%lf", &x[i]);
	}
	for(int i = 0;i < n;i++) {
		scanf("%lf", &y[i]);
	}

	for(int i = 0;i < n;i++) {
		p_1 += abs(x[i] - y[i]);
		p_2 += (x[i] - y[i]) * (x[i] - y[i]);
		p_3 += abs(pow((x[i] - y[i]), 3));
		p_inf = (p_inf >= abs(x[i] - y[i])) ? p_inf : abs(x[i] - y[i]);
	}

	printf("%.6lf\n", p_1);
	printf("%.6lf\n", sqrt(p_2));
	printf("%.6lf\n", cbrt(p_3));
	printf("%.6lf\n", p_inf);

	return 0;
}

