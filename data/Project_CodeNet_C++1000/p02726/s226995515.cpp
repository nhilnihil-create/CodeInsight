#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	ll n, x, y;
	cin >> n >> x >> y;
	x--; y--;
	vector<int> dis(n);
	rep(i, n) rep(j, i) {
		ll ans = i - j;
		ans = min(ans, abs(i - y) + abs(j - x) + 1);
		dis[ans]++;
	}
	rep(i, n - 1) cout << dis[i + 1] << endl;
	return 0;
}
//1-2-3-4-5-6-7
//  +---------+
