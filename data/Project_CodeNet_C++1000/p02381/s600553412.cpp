#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<cctype>
#include<string.h>

#define PI 3.1415926

int main(){
    	int n, s[2000];
		double sum = 0;
		double a2 = 0;
	while (1) {
	
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &s[i]);
			sum += s[i];
		}

		sum /= n;

		for (int i = 1; i <= n; i++) {
			a2 += (s[i] - sum)*(s[i] - sum);
		}
		printf("%f\n", sqrt(a2 / n));
		sum = 0;
		a2 = 0;
	}
	return 0;
}