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

	int x, y;
	cin >> x >> y;
	int ans = 0;
	ans += max(0, 4 - x);
	ans += max(0, 4 - y);
	ans += 4 * (x == 1 && y == 1);
	cout << ans * (100000) << endl;
}