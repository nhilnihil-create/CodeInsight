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

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &t : a) {
		cin >> t;
	}
	int ans = 0;
	auto appl = [&](int x) {
		vector<int> keks;
		for (auto t : a) {
			t %= x;
			if (t) keks.push_back(t);
		} 
		sort(keks.begin(), keks.end());
		int osum = 0;
		for (auto t : keks) {
			osum += t;
		}
		int csum = 0;
		for (int i = 0; i <= (int)keks.size(); i++) {
			if ((csum) == (((int)keks.size() - i) * x - (osum - csum))) {
				if (csum <= k) ans = max(ans, x);
			}
			if (i < (int)keks.size()) csum += keks[i];
		}
	};
	int s = 0;
	for (auto t : a) {
		s += t;
	}
	for (int i = 1; i * i <= s; i++) {
		if (s % i == 0) {
			appl(i);
			appl(s / i);
		}
	}
	// appl(7);
	cout << ans << endl;
}
