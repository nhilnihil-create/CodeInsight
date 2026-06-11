#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int h, w;
int main()
{
	int n;
	cin >> n;
	vector<P> d(n);
	rep(i, n) {
		int x, l;
		cin >> x >> l;
		d[i] = make_pair(x + l, x - l);
	}
	sort(d.begin(), d.end());
	int cur = -iINF;
	int ans = 0;
	rep(i, n) {
		if (cur <= d[i].second) {
			++ans;
			cur = d[i].first;
		}
	}
	cout << ans << endl;
	return 0;
}