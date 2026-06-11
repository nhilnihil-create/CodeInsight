#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <ctime>
#include <random>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define eps 1e-9
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;



int main() {
	speed;
	int h, w, m, a, b;
	cin >> h >> w >> m;
	map<int, int>x, y;
	set<pair<int, int>>p;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		x[a]++;
		y[b]++;
		p.insert({ a,b });
	}

	vector<int>mxx, mxy;
	int bx = 0, by = 0;
	for (auto i : x)
		bx = max(bx, i.second);
	for (auto i : x) {
		if (i.second == bx)
			mxx.push_back(i.first);
	}
	for (auto i : y)
		by = max(by, i.second);
	for (auto i : y) {
		if (i.second == by)
			mxy.push_back(i.first);
	}

	int ans = bx+by;
	bool d = 1;
	for (auto i : mxx) {
		for (auto j : mxy) {
			if (!p.count({ i,j })) {
				d = 0;
				goto ans;
			}
		}
	}
	ans:
	cout << ans - d;
}