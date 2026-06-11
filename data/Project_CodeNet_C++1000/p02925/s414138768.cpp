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

void nrm(pair<int, int> &a) {
	if (a.first > a.second) {
		swap(a.first, a.second);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i++) {
		a[i].resize(n - 1);
		for (auto &t : a[i]) {
			cin >> t;
			t--;
		}
		reverse(a[i].begin(), a[i].end());
	}
	map<pair<int, int>, int> cnt;
	set<pair<int, int>> bc[3];
	auto mk = [&](int i) {
		pair<int, int> v = {i, a[i].back()};
		nrm(v);
		int vw = cnt[v];
		if (vw == 1) bc[vw].erase(v);
		cnt[v]++;
		bc[cnt[v]].insert(v);
	};
	for (int i = 0; i < n; i++) {
		mk(i);
	}
	int ans = 0;
	while (true) {
		vector<pair<int, int>> tk;
		for (auto v : bc[2]) tk.push_back(v);
		if (tk.empty()) {
			break;
		}
		bc[2].clear();
		for (auto v : tk) {
			int i = v.first;
			int j = v.second;
			a[i].pop_back();
			a[j].pop_back();
			if (!a[i].empty()){
				mk(i);
			}
			if (!a[j].empty()) {
				mk(j);
			}
		}
		ans++;
	}
	for (int i = 0; i < n; i++) {
		if (!a[i].empty()) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
}
