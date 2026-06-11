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
#include <chrono>
#include <random>
#include <functional>

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> ed;
	for (int i = 1; i < n; i++) {
		ed.push_back({0, i});
	}
	int cans = (n - 1) * (n - 2) / 2;
	if (cans < k) {
		cout << -1 << endl;
		exit(0);
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (cans > k) {
				ed.push_back({i, j});
				cans--;
			}
		}
	}
	if (cans == k) {
		cout << ed.size() << endl;
		for (auto t : ed) {
			cout << t.first + 1 << ' ' << t.second + 1 << endl;
		}
	} else {
		cout << -1 << endl;
	}
}
