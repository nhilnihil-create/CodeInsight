#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int h, w, m;
	cin >> h >> w >> m;
	vector<pair<int, int>> arr(m);
	for (int i = 0; i < m; i++)
		cin >> arr[i].first >> arr[i].second;

	set<pair<int, int>> st;
	for (int i = 0; i < m; i++)
		st.insert(arr[i]);

	map<int, int> mpw, mph;
	for (int i = 0; i < m; i++)
		mpw[arr[i].first]++, mph[arr[i].second]++;

	int maxw = 0, maxh = 0;
	for (auto x : mpw)
		maxw = max(x.second, maxw);
	for (auto x : mph)
		maxh = max(x.second, maxh);

	set<int> stw, sth;
	for (auto x : mpw)
		if (x.second == maxw)
			stw.insert(x.first);

	for (auto x : mph)
		if (x.second == maxh)
			sth.insert(x.first);

	for (auto x : stw) {
		for (auto y : sth) {
			if (st.find({x, y}) == st.end()) {
				cout << maxw + maxh;
				return 0;
			}
		}
	}
	cout << maxw + maxh - 1;
	return 0;
}