#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<cctype>
#include<string.h>
#include <stdlib.h>

#define PI 3.1415926

int main(){
	int x[200], y[200],n;
	double  D1 = 0.00000, D2 = 0.00000, D3 = 0.00000,D4=0.00000;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &y[i]);
	}

	for (int i = 1; i <= n; i++) {
		D1 += abs(x[i] - y[i]);
		D2 += (x[i] - y[i])*(x[i] - y[i]);
		D3 += abs((x[i] - y[i])*(x[i] - y[i])*(x[i] - y[i]));
		if (abs(x[i] - y[i]) > D4) {
			D4 = abs(x[i] - y[i]);
		}
	}
	printf("%f %f %f %f\n", D1, sqrt(D2), pow(D3, 1.0 / 3.0), D4);
	return 0;
}