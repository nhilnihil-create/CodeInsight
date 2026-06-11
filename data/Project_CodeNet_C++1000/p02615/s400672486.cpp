#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

#define E_ACH2(x, a) for (auto& x: a)
#define E_ACH3(x, y, a) for (auto& [x, y]: a)
#define E_ACH4(x, y, z, a) for (auto& [x, y, z]: a)
#define E_ACHC(...) GET5(__VA_ARGS__, E_ACH4, E_ACH3, E_ACH2)
#define EACH(...) E_ACHC(__VA_ARGS__)(__VA_ARGS__)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	FOR(n)
		cin >> a[i];
	sort(all(a), greater<int>());
	vector<ll> b;
	FOR(n) {
		b.push_back(a[i]);
		if(i)
			b.push_back(a[i]);
	}
	ll ans=0;
	FOR(n-1)
		ans+=b[i];
	cout << ans;
}
