#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
//const int mod = 1000000007;

const int mod = 998244353;
struct mint {
	ll x;
	mint() :x(0) {}
	mint(ll x) :x((x% mod + mod) % mod) {}
	// mint(ll x):x(x){}
	mint& fix() { x = (x % mod + mod) % mod; return *this; }
	mint operator-() const { return mint(0) - *this; }
	mint& operator+=(const mint& a) { if ((x += a.x) >= mod) x -= mod; return *this; }
	mint& operator-=(const mint& a) { if ((x += mod - a.x) >= mod) x -= mod; return *this; }
	mint& operator*=(const mint& a) { (x *= a.x) %= mod; return *this; }
	mint operator+(const mint& a)const { return mint(*this) += a; }
	mint operator-(const mint& a)const { return mint(*this) -= a; }
	mint operator*(const mint& a)const { return mint(*this) *= a; }
	bool operator<(const mint& a)const { return x < a.x; }
	bool operator==(const mint& a)const { return x == a.x; }
};
istream& operator>>(istream & i, mint & a) { i >> a.x; return i; }
ostream& operator<<(ostream & o, const mint & a) { o << a.x; return o; }
typedef vector<mint> vm;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<ll> d(n);
	vector<ll> mp(n + 1);
	rep(i, n) {
		cin >> d[i];
		mp[d[i]]++;
	}
	if (d[0] != 0) {
		puts("0");
		return 0;
	}
	if (mp[0] != 1) {
		puts("0");
		return 0;
	}
	mint ans = 1;
	mint tmp = 1;
	rrep(i, n) {
		rep(j, mp[i]) ans *= tmp;
		tmp = mp[i];
	}
	dunk(ans);
	return 0;
}
