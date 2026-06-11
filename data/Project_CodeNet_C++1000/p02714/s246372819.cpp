#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

char u[3] = {'R', 'G', 'B'};

void solve() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	if (n <= 2) {
		cout << 0 << endl;
		return;
	}
	ll ans = 0;
	for (ll i = 1; i < n - 1; i++) {
		char c = s[i];
		vector<char> use;
		rep(j,3) {
			if (c == u[j]) continue;
			use.push_back(u[j]);
		}
		map<char, ll> lmp;
		vector<char> v;
		for (ll j = 0; j < i; j++) {
			if (s[j] == c) continue;
			lmp[s[j]]++;
		}
		map<char, ll> rmp;
		for (ll j = i + 1; j < n; j++) {
			if (s[j] == c) continue;
			rmp[s[j]]++;
		}
		ll x = lmp[use[0]] * rmp[use[1]];
		ll y = lmp[use[1]] * rmp[use[0]];
		ans += x + y;
	}

	ll ng = 0;
	for (ll i = 1; i < n - 1; i++) {
		for (ll j = 0; j < i; j++) {
			char c1 = s[i];
			char c2 = s[j];
			ll k = i + (i - j);
			if (c1 == c2) continue;
			if (k >= n) continue;
			if (c1 != s[k] && c2 != s[k]) ng++;
		}
	}
	cout << ans - ng << endl;
}

int main() {
	solve();
	return 0;
}