#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define pb push_back
#define fi first
#define se second

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}
ll LCM(ll x, ll y){
	return x/GCD(x, y)*y;
}

int main() {
	int x, y, a, b, c; cin >> x >> y >> a >> b >> c;
	ll p[100005], q[100005], r[100005];
	rep(i, 0, a) cin >> p[i];
	rep(i, 0, b) cin >> q[i];
	rep(i, 0, c) cin >> r[i];
	sort(p, p+a);
	sort(q, q+b);
	vector<ll> select;
	for(ll i=a-1;i>=a-1-(x-1);i--) select.pb(p[i]);
	for(ll i=b-1;i>=b-1-(y-1);i--) select.pb(q[i]);
	rep(i, 0, c) select.pb(r[i]);
	sort(select.rbegin(), select.rend());
	ll ans = 0;
	rep(i, 0, x+y){
		ans += select[i];
	}
	cout << ans << endl;
	return 0;
}