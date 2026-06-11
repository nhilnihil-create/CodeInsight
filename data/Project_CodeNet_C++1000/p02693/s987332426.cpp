#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < (ll)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	int k, a, b;
	cin >> k >> a >> b;
	string ans = "OK";
	if ((a - 1) / k == b / k) ans = "NG";
	cout << ans << endl;
	return 0;
}
