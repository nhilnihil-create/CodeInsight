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
	long long x_sums[200], y_sums[200];
	x_sums[0] = 0;
	y_sums[0] = 0;
	for (int i = 1; i <= N * 2 - 1; ++i) {
		x_sums[i] = x_sums[i - 1] + x[v[(i - 1) % N]];
		y_sums[i] = y_sums[i - 1] + y[v[(i - 1) % N]];
	}
	long long max = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j <= i + N; ++j) {
			long long x_sum = x_sums[j] - x_sums[i], y_sum = y_sums[j] - y_sums[i];
			long long value = x_sum * x_sum + y_sum * y_sum;
			if (value > max) {
				max = value;
			}
		}
	}
	std::printf("%.16lf", std::sqrt(max));
}