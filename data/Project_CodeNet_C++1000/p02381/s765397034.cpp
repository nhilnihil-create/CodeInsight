#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	int n;
	int x;
	int i;
	int sum;
	double sum2;
	double m;
	while(1) {
		scanf("%d", &n);
		if(n == 0) break;
		i = 0;
		vector<int> data;
		sum = 0;
		while(i < n) {
			cin >> x;
			data.push_back(x);
			sum += x;
			i++;
		}
		m = (double)sum / (double)n;

		sum2 = 0;
		for(i = 0; i < n; i++) {
			//printf("%d ", data[i]);
			sum2 += ((double)data[i] - m) * ((double)data[i] - m);
		}
		sum2 /= (double)n;
		printf("%lf\n", sqrt(sum2));
	}
	return 0;
}