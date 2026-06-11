#include <cstdio>
#include <math.h>
using namespace std;

int s[1001];

int main(){
	int n, sum;
	double m, sd;
	while (scanf("%d",&n) && n != 0) {
		sum = 0;
		sd = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d",&s[i]);
			sum += s[i];
		}
		m = 1.0*sum / n;
		for (int i = 0; i < n; i++) {
			sd += pow(s[i] - m, 2);
		}
		printf("%.6lf\n", sqrt(sd / n));
	}

	return 0;
}