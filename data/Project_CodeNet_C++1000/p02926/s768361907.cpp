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

#define int long long

typedef long double ld;

struct Vec {
	int x, y;

	Vec() {
		x = 0;
		y = 0;
	}

	Vec(int x_, int y_) {
		x = x_;
		y = y_;
	}

	Vec norm() const {
		return Vec(-y, x);
	}

	int operator%(const Vec &other) const {
		return x * other.x + y * other.y;
	}

	int operator*(const Vec &other) const {
		return x * other.y - y * other.y;
	}

	Vec operator+(const Vec &other) const {
		return Vec(x + other.x, y + other.y);
	}

	ld len() {
		return hypot((ld)x, (ld)y);
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<Vec> a(n);
	for (auto &t : a) {
		cin >> t.x >> t.y;
	}
	vector<Vec> v;
	for (int i = 0; i < n; i++) {
		Vec cur = a[i];
		for (int j = 0; j < 4; j++) {
			v.push_back(cur);
			cur = cur.norm();
		}
	}
	ld ans = 0;
	for (auto vc : v) {
		Vec cur;
		Vec f, s;
		for (auto t : a) {
			if ((vc % t) > 0) {
				cur = cur + t;
			} else if (vc % t == 0) {
				if (vc * t > 0) f = f + t;
				else s = s + t;
			} 
		}
		ans = max(ans, cur.len());
		{
			Vec c = cur + f;
			ans = max(ans, c.len());
		}
		{
			Vec c = cur + s;
			ans = max(ans, c.len());
		}
	}
	cout << fixed << setprecision(16);
	cout << ans << endl;
}
