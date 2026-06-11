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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &t : a) {
		cin >> t;
		t--;
		t %= k;
	}
	vector<int> ps(n + 1);
	for (int i = 0; i < n; i++) {
		ps[i + 1] = (ps[i] + a[i]) % k;
	}
	map<int, int> lol;
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (i >= k) {
			lol[ps[i - k]]--;
		}
		ans += lol[ps[i]];
		lol[ps[i]]++;
	}
	cout << ans << endl;
}
