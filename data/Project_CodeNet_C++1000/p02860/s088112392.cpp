#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
	int n;
	string s;
	cin >> n >> s;
	string a, b;
	for (int i = 0; i < n / 2; ++i)
		a += s[i];
	for (int i = n / 2; i < n; ++i)
		b += s[i];
	if (a == b)
		cout << "Yes";
	else
		cout << "No";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
}
