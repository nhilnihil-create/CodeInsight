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
	vector<int> a(n);
	for (auto &t : a) {
		cin >> t;
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			ans -= a[i];
		} else if (i + 1 == n) {
			ans += a[i];
		} else {
			ans += max(-a[i], a[i]);
		}
	}
	cout << ans << '\n';
	for (int i = 1; i + 1 < n; i++) {
		if (a[i] > 0) {
			cout << a[0] << ' ' << a[i] << '\n';
			a[0] -= a[i]; 
		} else {
			cout << a[n - 1] << ' ' << a[i] << '\n';
			a[n - 1] -= a[i];
		}
	}
	cout << a[n - 1] << ' ' << a[0] << '\n';
}