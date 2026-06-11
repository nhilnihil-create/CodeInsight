#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define all(vv) (vv).begin(), (vv).end()
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0

int n;
map <string, int> mp;
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ans = 0;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string x; cin >> x;
		sort(all(x));
		ans += mp[x];
		++mp[x];
	}
	cout << ans;
	time;
}