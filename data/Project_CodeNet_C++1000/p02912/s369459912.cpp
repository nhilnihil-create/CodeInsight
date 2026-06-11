#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m;
	multiset<int> s;
	cin >> n >> m;
	ll ss = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(-x);
		ss += x;
	}

	while (m > 0) {
		int f = -*s.begin();
		s.erase(s.begin());
		ss -= f - f / 2;
		s.insert(-f / 2);
		m--;
	}
	cout << ss;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}