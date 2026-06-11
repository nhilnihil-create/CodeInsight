#include<bits/stdc++.h>
using namespace std;
void solve() {
	int l, r, d;
	cin >> l >> r >> d;
	int ans = (l % d) ? 0 : 1;
	ans += (r / d) - (l / d);
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}