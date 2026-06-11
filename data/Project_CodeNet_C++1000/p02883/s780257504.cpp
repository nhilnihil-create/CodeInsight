#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
template<class T> using pq = priority_queue<T>;
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
ll Ceil(ll x, ll y) {
	return (x + y - 1) / y;
}
bool judge(ll x, VL& a, VL& b, ll k) {
	ll used = 0;
	rep(i, a.size()) {
		if (a[i] * b[i] > x) {
			ll tot = a[i] * b[i];
			tot -= x;
			used += Ceil(tot, b[i]);
		}
	}
	return used <= k;
}
int main() { // 問題文はしっかり読め!!!
	int n; ll k;
	cin >> n >> k;
	VL a(n);
	VL b(n);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
	}
	sort(all(a));
	sort(all(b), greater<ll>());
	ll ok = 1e12 + 1, ng = -1;
	while (ok - ng > 1) {
		ll mid = (ok + ng) / 2;
		if (judge(mid, a, b, k)) ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
	return 0;
}