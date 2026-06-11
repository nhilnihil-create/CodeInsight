#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mp  make_pair
#define pb  push_back
#define endl "\n"
#define rep(i,a,n) for(int i=a;i<n;i++)
const int mod = 1e9 + 7;
void solve() {
	string s;
	cin >> s;
	int k = 0;
	int n = s.size();
	rep(i, 0, n) {
		k += (int)(s[i] - '0');
	}
	if (k % 9 == 0) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int t;
	t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
