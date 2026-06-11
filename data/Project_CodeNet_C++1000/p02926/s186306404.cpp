#include <cstdio>
#include <algorithm>
#include <cmath>

int main() {
	int N, x[100], y[100], v[100];
	std::scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		std::scanf("%d %d", x + i, y + i);
		v[i] = i;
	}
	std::sort(v, v + N, [&](int a, int b) {
		return std::atan2((double) y[a], (double) x[a]) < std::atan2((double) y[b], (double) x[b]);
	});

	long long max = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j <= i + N; ++j) {
			long long x_sum = 0, y_sum = 0;
			for (int k = i; k < j; ++k) {
				x_sum += x[v[k % N]];
				y_sum += y[v[k % N]];
			}
			long long value = x_sum * x_sum + y_sum * y_sum;
			if (value > max) {
				max = value;
			}
		}
	}
	std::printf("%.16lf", std::sqrt(max));
}