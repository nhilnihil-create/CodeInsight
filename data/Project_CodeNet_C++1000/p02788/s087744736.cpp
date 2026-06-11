#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<V>;
using VVV = vector<VV>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
template<class T> using VE = vector<T>;
template<class T> using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
int nxtpos(VE<P<ll>>& a, ll d, ll now) {
	int l = 0, r = a.size();
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (a[mid].first <= now + d) l = mid;
		else r = mid;
	}
	l++;
	return l;
}
int main() {
	ll n, d, e;
	cin >> n >> d >> e;
	d = 2 * d; // 2*d+1だと区間を1余計に含むからダメでは？
	VE<P<ll>> a(n);
	rep(i, n) {
		ll x;
		cin >> a[i].first >> x;
		a[i].second = (x + e - 1) / e;
	}
	VL imos(n + 1, 0); // 区間iの爆弾が使われた回数をimos法で効率よく処理
	ll ans = 0;
	sort(all(a));
	rep(i, n) {
		if (i != 0) imos[i] += imos[i - 1];
		a[i].second -= imos[i];
		ll use = max((ll)0, a[i].second);
		ans += use;
		imos[i] += use;
		int index = nxtpos(a, d, a[i].first);
		imos[index] -= use;
	}
	cout << ans << endl;
	return 0;
}