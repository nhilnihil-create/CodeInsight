#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < (ll)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	int ans = 0;
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	vector<int> m(2019);
	int p = 1, n = 0;
	m[0]++;
	for(char c : s) {
		int x = c - '0';
		x = (x * p + n) % 2019;
		n = x;
		p = (p * 10) % 2019;
		ans += m[x];
		m[x]++;
	}
	cout << ans << endl;
	return 0;
}
