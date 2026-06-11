#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <climits>
#include <iomanip>

using namespace std;

const int N = 2e6 + 9;
const int INF = 2e9 + 2;
const int mod = 1e9 + 7;
const int K = 25;
const int P = 51;
const long long LONG_INF = LONG_MAX;
const int SZ = (1 << 18) - 1;

#define eb emplace_back
#define sz(s) (int)(s.size())
#define mkp make_pair
#define all(s) s.begin(), s.end()

#define ll long long

#define int ll
void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector <int> a(n);
	for (int i = 0; i < n; ++ i)
		a[i] = s[i] - '0' - 1;
	bool ok = false;
	for (int i = 0; i < n; ++ i)
		if (a[i] == 1)
			ok = true;
	
	if (ok)
		for (int i = 0; i < n; ++ i)
			a[i] %= 2;
	int ans = 0;

	for (int i = 0; i < n; ++ i)
		if (((n - 1) & i) == i)
			ans ^= a[i];
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	solve();
	return 0;
}
