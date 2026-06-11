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

	int h, w, n;
	cin >> h >> w >> n;
	vector<int> cnt(w);
	vector<vector<int>> by_h(h);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		by_h[x].push_back(y);
		cnt[y]++;
	}
	set<pair<int, int>> s;
	for (int i = 0; i < w; i++) {
		s.insert({cnt[i], i});
	}
	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (auto j : by_h[i]) {
			s.erase({cnt[j], j});
			cnt[j]--;
			s.insert({cnt[j], j});
		}
		ans = max(ans, (int)by_h[i].size() + s.rbegin()->first);
		for (auto j : by_h[i]) {
			s.erase({cnt[j], j});
			cnt[j]++;
			s.insert({cnt[j], j});
		}
	}
	cout << ans << '\n';
}