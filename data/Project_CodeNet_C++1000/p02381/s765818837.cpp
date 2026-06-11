#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	while (1)
	{
		int n;
		cin >> n;
		if (!(n == 0)) {
			vector<int> s(n);
			double sum = 0;
			for (int i = 0; i < n; ++i) {
				cin >> s[i];
				sum += s[i];
			}
			double m = sum / n;

			double alpha;
			double sum_alpha = 0;
			for (int j = 0; j < n; ++j) {
				sum_alpha += pow((s[j] - m), 2);
			}
			alpha = sqrt(sum_alpha / n);
			printf("%.5f\n", alpha);
		}
		else {
			break;
		}
	}
	return 0;
}