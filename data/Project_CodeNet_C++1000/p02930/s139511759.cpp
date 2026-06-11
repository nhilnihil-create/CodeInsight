#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	auto color = [&](int a, int b) {
		for (int i = 20; i >= 0; i--) {
			if (((a >> i) & 1) != ((b >> i) & 1)) {
				return i + 1;
			}
		}
		return -1;
	};
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cout << color(i, j) << ' ';
		}
		cout << endl;
	}
}
