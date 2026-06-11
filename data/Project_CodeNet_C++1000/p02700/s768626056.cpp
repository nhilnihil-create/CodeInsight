#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < (ll)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	int h, a, eh, ea;
	string ans = "Yes";
	cin >> h >> a >> eh >> ea;
	int x, y;
	x = (h + ea - 1) / ea;
	y = (eh + a - 1) / a;
	if (x < y) ans = "No";
	cout << ans << endl;
	return 0;
}
