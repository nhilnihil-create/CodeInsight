#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

int main() {
	long long N; std::cin >> N;
	std::vector<int> A(N);
	long long all = 0;
	for (auto& r : A) {
		std::cin >> r;
		all += r;
	}
	long long dall = 0;
	long long p = 0;
	for (long long i = 0; i < N; ++i) {
		dall += A[i];
		if (dall > all / 2) {
			p = i;
			break;
		}
	}
	dall -= A[p];
	long long dall2 = 0;
	long long p2 = 0;
	for (long long i = N - 1; i >= 0; --i) {
		dall2 += A[i];
		if (dall2 > all / 2) {
			p2 = i;
			break;
		}
	}
	dall2 -= A[p2];
	std::cout << std::min(all - (dall * 2), all - (dall2 * 2)) << std::endl;

}
