#include "bits/stdc++.h"
using namespace std;

// Inserted snippets: io, root
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }
// End snippets

ll calc(ll x) {
	return x / 2;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	string s; int k;
	read(s, k);
	int n = sz(s);
	vector<pair<char, int>> v;
	
	int prev = 0;
	for (int i = 1; i < sz(s); i++) {
		if (s[i] != s[prev]) {
			v.push_back({s[prev], i - prev});
			prev = i;
		}
	}
	v.push_back({s[prev], n - prev});
	
	if (v.size() == 1) {
		write(calc(1ll * n * k));
	} else {
		ll ans = 0;
		ans += calc(v[0].second);
		ans += calc(v[sz(v) - 1].second);
		rep(i, 1, sz(v) - 1)
			ans += 1ll * calc(v[i].second) * k;
		if (v[0].first == v[sz(v) - 1].first)
			ans += calc(v[0].second + v[sz(v) - 1].second) * (k - 1);
		else
			ans += (calc(v[0].second) + calc(v[sz(v) - 1].second)) * (k - 1);
		write(ans);
	}
}
