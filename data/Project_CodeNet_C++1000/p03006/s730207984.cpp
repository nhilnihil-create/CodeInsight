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


using namespace std;
using P = pair< int , int >;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

int main() {
	int n;
	cin >> n;
	map< P, int > ps;
	int x[n], y[n];

	rep(i , n) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];

			if (dx == 0) {
				if (dy < 0) {
					dy *= -1;
				}
			} else if (dx < 0) {
				dx *= -1;
				dy *= -1;
			}
			ps[mp(dx,dy)] ++;
		}
	}
	int max_v = 0;
	for ( auto p : ps) {
		max_v = max(p.second, max_v);
	}


	cout << n - max_v << endl;	
	return 0;
}