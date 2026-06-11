#include <sys/time.h>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using i_i = pair<int, int>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
const ll mod = 1000000007LL;


int main() {
	int h, w, m;

	cin >> h >> w >> m;

	set<i_i> ps;

	map<int, int> xs;
	map<int, int> ys;


	rep(i, m) {
		int y, x;
	
		cin >> y >> x;
		ps.insert(mkp(y,x));

		ys[y]++;
		xs[x]++;
		
	}
	int y_max = 0;
	int x_max = 0; 
	for(auto cur : ys) {
		y_max = max(y_max, cur.second);

	}
	for(auto cur : xs) {
		x_max = max(x_max, cur.second);	
	}

	vector<int> xps;
	vector<int> yps;

	for(auto cur : ys) {
		if (cur.second == y_max) {
			yps.push_back(cur.first);
		}
	}
	for(auto cur : xs) {
		if (cur.second == x_max) {
			xps.push_back(cur.first);
		}
	}

	for(int y: yps) {
		for (int x: xps) {
			if (ps.find(mkp(y, x)) == ps.end()) {
				cout << x_max + y_max << endl;				
				return 0;
			}
		}
	}

	cout << x_max + y_max - 1 << endl;

	return 0;
}
