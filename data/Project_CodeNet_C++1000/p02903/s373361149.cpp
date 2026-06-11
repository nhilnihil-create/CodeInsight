#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	vector<vector<int>> ans(h, vector<int>(w, 0));
	for (int i = 0; i < b; ++i) {
		for (int j = a; j < w; ++j) {
			ans[i][j] = 1;
		}
	}
	for (int i = b; i < h; ++i) {
		for (int j = 0; j < a; ++j) {
			ans[i][j] = 1;
		}
	}
	rep(i, h) {
		rep(j, w) {
			cout << ans[i][j];
		}
		cout << endl;
	}

	return 0;
}