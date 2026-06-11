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

const int INF = 2e9 + 239;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> mx(4, -INF);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		mx[0] = max(mx[0], x + y);
		mx[1] = max(mx[1], x - y);
		mx[2] = max(mx[2], -x - y);
		mx[3] = max(mx[3], -x + y);
	} 
	cout << max(mx[0] + mx[2], mx[1] + mx[3]) << endl;
}