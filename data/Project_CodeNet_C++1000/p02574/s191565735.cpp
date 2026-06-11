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

const int N = 1e6 + 7;

int cnt[N];
vector<int> divs[N];

void init() {
	for (int i = 2; i < N; i++) {
		if (divs[i].empty()) {
			for (int j = i; j < N; j += i) {
				divs[j].push_back(i);
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();
	int g = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		g = gcd(g, x);
		for (auto dv : divs[x]) {
			cnt[dv]++;
		}
	}
	int any = 0;
	for (int i = 0; i < N; i++) {
		any |= (cnt[i] > 1);
	}
	if (!any) {
		cout << "pairwise coprime\n";
	} else if (g == 1) {
		cout << "setwise coprime\n";
	} else {
		cout << "not coprime\n";
	}
}