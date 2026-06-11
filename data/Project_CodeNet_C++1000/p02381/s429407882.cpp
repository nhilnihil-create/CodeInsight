// class point	の練習（クラスの高度な実装）
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

typedef long long llong;
using namespace std;

int main() {
	int n;
	int score[1100];
	double mean, var;
	while (1) {
		scanf("%d", &n);
		if (!n)break;
		mean = 0; var = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &score[i]);
			mean += (double)score[i];
		}
		mean /= n;
		for (int i = 0; i < n; i++) {
			var += ((double)score[i] - mean)*((double)score[i] - mean);
		}
		var /= n;
		cout << fixed << setprecision(10) << sqrt(var) << endl;
		

	}
	return 0;
}

