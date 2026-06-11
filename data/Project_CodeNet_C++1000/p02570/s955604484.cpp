#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int d, t, s;
	cin >> d >> t >> s;
	if (s * t >= d) cout << "Yes";
	else cout << "No";
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