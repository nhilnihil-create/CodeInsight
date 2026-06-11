#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<pair<int, int> > v(n);
	for (auto &u : v)cin >> u.first >> u.second;
	for (int i = 2; i < n; i++) {
		if (v[i].first == v[i].second && v[i - 1].first == v[i - 1].second && v[i - 2].first == v[i - 2].second) {
			cout << "Yes\n"; return ;
		}
	}
	cout << "No"; return ;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// int t; cin >> t;
	// while (t--)
	solve();

}