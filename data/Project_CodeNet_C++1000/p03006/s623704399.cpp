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

	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			int save = 0;
			for (int f = 0; f < n; f++) {
				int nx = x[f] + dx;
				int ny = y[f] + dy;
				int any = 0;
				for (int s = 0; s < n; s++) {
					if (nx == x[s] && ny == y[s]) {
						any = 1;
					}
				}
				save += any;
			}
			ans = max(ans, save);
		}
	}
	cout << n - ans << '\n';
}