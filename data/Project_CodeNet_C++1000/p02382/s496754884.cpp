#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void)
{
	int n, x[100], y[100];
	double d, max;
	int i, j;


	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", &x[i]);
	for(i=0;i<n;i++)
		scanf("%d", &y[i]);


	for(i=1;i<=3;i++){
		d = 0;
		for(j=0;j<n;j++){
			d += pow(abs(x[j] - y[j]), i);
		}
		d = pow(d, 1.0 / i);
		printf("%f\n", d);
	}


	max = 0;
	for(i=0;i<n;i++){
		if(abs(x[i] - y[i]) > max)
			max = abs(x[i] - y[i]);
	}
	printf("%f\n", max);

	return 0;
}