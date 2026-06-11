#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lli = long long int;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vlli = vector<lli>;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i > 0; i--)
#define all(v) v.begin(), v.end()
#define debug(x) cout << x << endl
#define vout(v) rep(i, v.size()) cout << v[i] << " ";

string s;

int solve() {
	while (s != "") {
		if (s.substr(0, 2) == "hi") {
			s = s.substr(2);
		} else {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}

int main() {
	cin >> s;

	solve();
	return 0;
}