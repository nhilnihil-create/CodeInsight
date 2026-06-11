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
ll solve(int n, int p, string s) {
	map<int, ll> mp;
	mp[0]++;
	ll mul = 1;
	V mod(n + 1, 0);
	rep(i, n) {
		int num = (s[i] - '0') * mul % p;
		mod[i + 1] = (mod[i] + num) % p;
		mp[mod[i + 1]]++;
		mul = mul * 10 % p;
	}
	ll ans = 0;
	for (auto c : mp) {
		ans += c.second * (c.second - 1) / 2;
	}
	return ans;
}
ll solve2(int n, int p, string s) {
	ll ans = 0;
	rep(i, n) {
		int digit = s[i] - '0';
		if (digit % p == 0) ans += n - i;
	}
	return ans;
}
int main() {
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	reverse(all(s));
	if (p == 2 || p == 5) cout << solve2(n, p, s) << endl;
	else cout << solve(n, p, s) << endl;
	return 0;
}