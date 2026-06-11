#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;
using P = pair<ll, ll>;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
using Graph = VV;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Inf = (1 << 30);
ll inf = (1LL << 60);
const int MOD = 1e9 + 7;
const int betsumono = 998244353;
ll modpow(ll a, ll b, ll M) {
	ll res = 1;
	for (; b > 0; b >>= 1) {
		if (b & 1) res = (res * a) % M;
		a = a * a % M;
	}
	return res;
}
ll mypow(ll x, ll y) {
	if (x == 0 || y == 0) return 0;
	else return modpow(x, y, betsumono);
}
int main() {
	int n;
	cin >> n;
	int i;
	V a(n);
	VL count(100000,0);
	bool start = false;
	rep(i, n) {
		cin >> a[i];
		if (i == 0 && a[i] == 0) start++;
		count[a[i]]++;
	}
	if (!start || count[0] >= 2) {
		cout << 0 << endl;
		return 0;
	}
	int MAX = *max_element(all(a));
	ll ans = 1;
	for (i = 1; i <= MAX; i++) {
		ll P = mypow(count[i - 1], count[i]); // オーバーフローに気を付ける(普通にans*powだとダメだった)
		ans *= P;
		ans %= betsumono;
	}
	cout << ans << endl;
	return 0;
}