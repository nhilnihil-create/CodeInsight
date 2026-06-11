/* https://codeforces.com/contest/1360/problem/H */
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vs = vector<string>;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pair<int, int>>;
using vpl = vector<pair<ll, ll>>;
using ld = double;

#define f first
#define s second 
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define pb push_back
#define	lb lower_bound
#define	ub upper_bound
#define	sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define ins insert
#define mp make_pair

const int MAX = INT_MAX;

int main() {
	int H, W, M;
	cin>>H>>W>>M;
	map<ll, ll> r;
	map<ll, ll> c;
	map<pair<ll, ll>, bool> values;
	ll max_r = 0, max_c = 0;
	for (int i = 0;i < M;++i) {
		ll x, y;
		cin>>x>>y;
		values[mp(x, y)] = true;
		r[x] += 1;
		max_r = max(max_r, r[x]);
		c[y] += 1;
		max_c = max(max_c, c[y]);
	}

	vector<ll> max_rows;
	vector<ll> max_cols;

	for (auto& x : r) {
		if (x.second == max_r) {
			max_rows.pb(x.first);
		}
	}

	for (auto& x : c) {
		if (x.second == max_c) {
			max_cols.pb(x.first);
		}
	}

	bool f = false;
	for (int i = 0;i < max_rows.size() && !f;++i) {
		for (int j = 0;j < max_cols.size() && !f;++j) {
			if (!values[mp(max_rows[i], max_cols[j])]) {
				f = true;
				break;
			}
		}
	}

	printf("%lld\n", f ? max_r + max_c : max_r + max_c - 1);
	return 0;
}
