#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 1000

int main(void)
{
	int n,i;
	double a[MAX];
	double ave,sum;
	while (1) {
		scanf("%d",&n);
		if (n == 0) {
			break;
		}
		else {
			sum = 0;
			for (i=0; i<n; i++) {
				scanf("%lf",&a[i]);
				sum += a[i];
			}
			ave = sum/n;
			sum = 0;
			for (i=0; i<n; i++) {
				sum += (a[i] - ave)*(a[i]-ave);
			}
			printf("%lf\n", sqrt(sum/n));
		}
	}
	return 0;
}

