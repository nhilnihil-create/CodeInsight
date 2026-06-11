#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<ll> v(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i)v[j]++;
	}
//	for (int i : v)cout << i << ' '; cout << endl;
	cout << accumulate(v.begin(), v.begin() + n , 0ll) << endl;
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