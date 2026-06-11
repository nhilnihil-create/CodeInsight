#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>
#include <iterator>
#include <cassert>

typedef long long ll;
typedef unsigned long long ull;
constexpr ll mop = 1000000007;
constexpr ll mop2 = 998244353;

using namespace std;

int main() {
	ll h, w;
	cin >> h >> w;
	vector<vector<bool>> grid(h + 1);
	vector<vector<ll>> rowObstacleList(h + 1), colObstacleList(w + 1);
	for (ll i = 1; i <= h; i++) {
		rowObstacleList[i].push_back(0);
	}
	for (ll i = 1; i <= w; i++) {
		colObstacleList[i].push_back(0);
	}
	for (ll i = 1; i <= h; i++) {
		grid[i].resize(w + 1);
		string s;
		cin >> s;
		for (ll j = 1; j <= w; j++) {
			if (s[j - 1] == '#') {
				grid[i][j] = false;
				rowObstacleList[i].push_back(j);
				colObstacleList[j].push_back(i);
			}
			else {
				grid[i][j] = true;
			}
		}
	}
	for (ll i = 1; i <= h; i++) {
		rowObstacleList[i].push_back(w+1);
	}
	for (ll i = 1; i <= w; i++) {
		colObstacleList[i].push_back(h+1);
	}

	ll ans = 0;
	for (ll i = 1; i <= h; i++) {
		for (ll j = 1; j <= w; j++) {
			if (grid[i][j]) {
				ll l, r, u, d;
				auto itr = lower_bound(rowObstacleList[i].begin(), rowObstacleList[i].end(), j);
				r = *itr;
				l = *(--itr);
				itr = lower_bound(colObstacleList[j].begin(), colObstacleList[j].end(), i);
				d = *itr;
				u = *(--itr);
				ll tmp = (r - l - 1) + (d - u - 1) - 1;
				
				if (ans < tmp) {
					ans = tmp;
				}
			}
		}
	}
	cout << ans << endl;

}

