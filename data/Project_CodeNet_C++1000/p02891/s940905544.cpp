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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	int n = (int)s.size();
	int k;
	cin >> k;
	vector<int> cnt;
	for (int i = 0; i < n; i++) {
		int r = i;
		while (r + 1 < n && s[r] == s[r + 1]) {
			r++;
		}
		cnt.push_back(r - i + 1);
		i = r;
	}
	if ((int)cnt.size() == 1) {
		cout << ((n * k)) / 2 << endl;
		return 0;
	}
	if (s[0] == s[n - 1]) {
		int ans = 0;
		for (int i = 1; i + 1 < (int)cnt.size(); i++) {
			ans += k * ((cnt[i]) / 2);
		}
		ans += (k - 1) * (((cnt.front() + cnt.back())) / 2);
		ans += (cnt.front()) / 2;
		ans += (cnt.back()) / 2;
		cout << ans << endl; 
	} else {
		int ans = 0;
		for (int i = 0; i < (int)cnt.size(); i++) {
			ans += k * ((cnt[i]) / 2);
		}
		cout << ans << endl;
	}
}