#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, x[100], y[100];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &x[i]);
	for(int i = 0; i < n; i++) scanf("%d", &y[i]);
	for(int i = 1; i < 4; i++) {
		long long sum = 0;
		for(int j = 0; j < n; j++) sum += pow(abs(x[j] - y[j]), i);
		printf("%.9f\n", pow(sum, 1.0 / i));
	}
	int r = 0;
	for(int i = 0; i < n; i++) r = max(r, abs(x[i] - y[i]));
	printf("%d\n", r);
	return 0;
}