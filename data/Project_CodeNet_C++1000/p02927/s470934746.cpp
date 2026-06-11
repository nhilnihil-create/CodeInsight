#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int ans = 0;
	int M, D;
	cin >> M >> D;
	for (int m = 1; m <= M; m++) {
		for (int d = 20; d <= D; d++) {
			if (d % 10 >= 2 && (d / 10) * (d % 10) == m) {
				ans++;
			}
		}
	}
	cout << ans;
}
