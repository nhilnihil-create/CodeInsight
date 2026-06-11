#include <iostream>
#include <cstring>

long long h[1500001], w[1500001];
long long hh[1500], ww[1500];

int main() {
	int n, m;
	while (std::cin >> n >> m && (n || m)) {
		std::memset(h, 0, sizeof(h));
		std::memset(w, 0, sizeof(w));

		int numX = 0, numY = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> hh[i];
		}
		for (int i = 0; i < m; i++) {
			std::cin >> ww[i];
		}

		for (int sy = 0; sy < n; sy++) {
			for (int y = 0; y < n - sy; y++) {
				long long num = 0;
				for (int i = 0; i <= sy; i++) {
					num += hh[i + y];
				}
				h[num]++;
			}
		}

		for (int sx = 0; sx < m; sx++) {
			for (int x = 0; x < m - sx; x++) {
				int num = 0;
				for (int i = 0; i <= sx; i++) {
					num += ww[i + x];
				}
				w[num]++;
			}
		}

		long long cnt = 0;
		for (int i = 0; i < 1500001; i++) {
			cnt += h[i] * w[i];
		}

		std::cout << cnt << std::endl;
	}

	return 0;
}