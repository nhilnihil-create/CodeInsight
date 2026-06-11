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

#define int long long

int acc(vector<int> a, int len) {
	int n = (int)a.size();
	int s = 0;
	for (auto t : a) {
		s += t;
	}
	int ans = s * (len / n);
	len %= n;
	for (int i = 0; i < len; i++) {
		ans += a[i];
	}
	return ans;
}

void solve(vector<int> d) {
	int x, len, mod;
	cin >> len >> x >> mod;
	vector<int> zr;
	for (auto &t : d) {
		t %= mod;
		zr.push_back((t == 0));
	}
	x %= mod;
	int bg = (x + acc(d, len - 1)) / mod;
	int eq = acc(zr, len - 1);
	cout << len - 1 - eq - bg << endl;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int k, q;
	cin >> k >> q;
	vector<int> d(k);
	for (auto &t : d) {
		cin >> t;
	}
	while (q--) {
		solve(d);
	}
}
