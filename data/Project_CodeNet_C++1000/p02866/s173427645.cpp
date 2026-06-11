#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <iterator>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
const int MOD = 998244353;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	int n;
	cin >> n;
	vector<int> d(n);
	rep(i, n) cin >> d[i];
	if (d[0] != 0) {
		cout << 0 << endl;
		return 0;
	}
	sort(d.begin(), d.end());
	if (n == 1 && d[0] == 0) {
		cout << 1 << endl;
		return 0;
	}
	else if (n == 1 && d[0] != 0) {
		cout << 0 << endl;
		return 0;
	}
	if (d[0] == 0 && d[1] == 0) {
		cout << 0 << endl;
		return 0;
	}
	rep(i, n - 1) {
		if (2 <= d[i + 1] - d[i]) {
			cout << 0 << endl;
			return 0;
		}
	}
	map<int, int> mp;
	rep(i, n) {
		mp[d[i]]++;
	}
	ll ans = 1;
	for (auto itr = mp.rbegin(); itr != prev(mp.rend()); ++itr) {
		rep(i, itr->second) {
			ans *= ll(next(itr)->second);
			ans %= ll(MOD);
		}
	}
	cout << ans << endl;
	return 0;
}