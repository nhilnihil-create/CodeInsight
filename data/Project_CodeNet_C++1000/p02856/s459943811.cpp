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

	int n;
	cin >> n;
	int LEN = 0;
	int S = 0;
	for (int i = 0; i < n; i++) {
		int d, c;
		cin >> d >> c;
		LEN += c;
		S += d * c;
	}
	int VAL = (9 * LEN + S - 1);
	cout << VAL / 9 - 1 << endl;
}