#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(ll n) {
	string res;
	while (n--) {
		ll d = n % 26;
		res.push_back(d+97);
		n /= 26;
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	solve(n);
	return 0;
}