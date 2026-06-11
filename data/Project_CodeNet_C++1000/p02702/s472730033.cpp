#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	reverse(s.begin(), s.end());
	int p = 2019;
	int cur = 0;
	int ten = 1;
	map<int, int> ost;
	ost[0] = 1;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ten *= 10;
		ten %= p;
		cur += (s[i] - '0') * ten;
		cur %= p;
		ans += ost[cur]++;
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q = 1;
	//cin >> q;
	for (; q > 0; q--) {
		solve();
		cout << endl;
	}
}