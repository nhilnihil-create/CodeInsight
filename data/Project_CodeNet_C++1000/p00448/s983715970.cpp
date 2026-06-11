#include <iostream>
#include <algorithm>
#include <cstring>

// bit
unsigned int senbei[10000];

int main() {
	unsigned int r, c;
	while (std::cin >> r >> c, r + c != 0) {
		std::memset(senbei, 0, sizeof(senbei));
		for (unsigned int i = 0; i < r; ++i) {
			for (unsigned int j = 0; j < c; ++j) {
				unsigned int b;
				std::cin >> b;
				senbei[j] |= (b << i);
			}
		}

		const unsigned int maskUp = 1u << r;
		int ans = 0;
		for (unsigned int mask = 0; mask < maskUp; ++mask) {
			int count = 0;

			for (unsigned int i = 0; i < c; ++i) {
				auto reversed = senbei[i] ^ mask;
				int num = 0;
				while (reversed != 0) {
					++num;
					reversed &= reversed - 1;
				}

				count += (num > r / 2 ? num : r - num);
			}

			ans = std::max(ans, count);
		}

		std::cout << ans << std::endl;
	}
}