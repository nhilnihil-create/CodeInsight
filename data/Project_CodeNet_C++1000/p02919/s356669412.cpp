#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = s; i < (int)n; i++)
#define all(obj) obj.begin(), obj.end()
#define debug(x) cerr << #x << ":" << x << "\n"
#define vdebug(vec) cerr << #vec << ":"; for (auto e : vec) cerr << e << " "; cout << "\n"
#define YN(f) cout << (f ? "YES" : "NO") << endl
#define Yn(f) cout << (f ? "Yes" : "No") << endl
#define yn(f) cout << (f ? "yes" : "no") << endl
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main () {
	int N; cin >> N;
	vi P(N); // index -> value
	map<int, int> m; // value -> index
	rep(i, N) { // 0-indexed
		cin >> P.at(i); // index -> value
		m[P.at(i)] = i; // value -> index
	}	
	// vdebug(P);
	// for (auto mi : m) cout << mi.first << " " << mi.second << endl;
	set<int> s;
	s.insert(-2); s.insert(-1); s.insert(N); s.insert(N + 1); // 番兵 ※重複不可のため
	ll ans = 0;
	for (int k = N; k > 0; k--) { // k:value
		s.insert(m.at(k)); // indexを入れる		
		auto it = s.lower_bound(m.at(k)); // 値kに対応する添字xに対応するiterator
		// auto it = lower_bound(all(s), m.at(k)); // ダメな例
		ll l2 = max(*prev(prev(it)), -1);
		ll l1 = *prev(it);
		ll x = *it;
		ll r1 = *next(it);
		ll r2 = min(*next(next(it)), N);
		// debug(k);
		// for (auto si : s) cout << si << " "; cout << endl;
		// debug (l2); debug(l1); debug(x); debug(r1); debug(r2);
		ll temp = k * ((l1 - l2) * (r1 - x) + (x - l1) * (r2 - r1));
		// debug(temp);
		ans += temp;
	}

	cout << ans << endl;
}
