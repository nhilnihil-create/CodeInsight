#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cfloat>
#include <climits>
#include <cassert>
#include <random>
#include <bitset>
#include <memory>

int main() {
	int k, q; std::cin >> k >> q;
	std::vector<int> diff(k); for (auto& d : diff) std::cin >> d;
	for (auto i = 0; i < q; ++i) {
		int n, x, m; std::cin >> n >> x >> m;
		long long int back = 0;
		long long int part = 0;
		int just = 0;
		int part_just = 0;
		for (auto j = 0; j < diff.size(); ++j) {
			back += diff[j] % m;
			if (diff[j] % m == 0) ++just;
			if (j == (n - 2) % k) {
				part = back;
				part_just = just;
			}
		}
		long long int max = x + back * ((n - 2) / k) + part;
		long long int min = x;
		long long int dec = max / m - min / m;
		std::cout << n - 1LL - dec - just * ((n - 2LL) / k) - part_just << '\n';
	}
}
