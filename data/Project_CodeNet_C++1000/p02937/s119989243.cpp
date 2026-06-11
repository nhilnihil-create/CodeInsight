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
int main() {
	string s, t;
	cin >> s >> t;
	int x = s.size(), y = t.size();
	VV pos(26);
	rep(i, x) {
		int c = s[i] - 'a';
		pos[c].push_back(i + 1);
	}
	rep(i, 26) {
		int z = pos[i].size();
		rep(j, z) {
			pos[i].push_back(pos[i][j] + x);
		}
	}
	rep(i, y) {
		if (pos[t[i] - 'a'].size() == 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	ll ans = 0;
	ll posnow = 0;
	rep(i, y) {
		int c = t[i] - 'a';
		auto itr = upper_bound(all(pos[c]), posnow);
		ans += *itr - posnow;
		posnow = *itr;
		if (posnow > x) posnow -= x;
	}
	cout << ans << endl;
	return 0;
}