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
ll Upper = UPPER / 100000;
const long double pi = 3.141592653589793;
int main() {
	int n;
	cin >> n;
	V a(n + 1);
	rep(i, n + 1) {
		cin >> a[i];
	}
	if (n == 0 && a[0] == 1) {
		cout << 1 << endl;
		return 0;
	}
	else if (n == 0 && a[0] != 1) {
		cout << -1 << endl;
		return 0;
	}
	else if (n != 0 && a[0] != 0) {
		cout << -1 << endl;
		return 0;
	}
	/*
	最終的な頂点の数はa[n]である
	そこを超えないようにとる？
	*/
	VL wants(n + 1, 1);
	ll nxt = 1;
	ll maxi = a[n];
	rep1(i, n) {
		ll Nxt = nxt * 2;
		chmin(Nxt, Upper);
		nxt = Nxt;
		nxt -= a[i];
		wants[i] = nxt;
		if (nxt <= 0 && i != n) {
			cout << -1 << endl;
			return 0;
		}
		if (nxt < 0 && i == n) {
			cout << -1 << endl;
			return 0;
		}

	}
	ll ans = a[n];
	for (int i = n - 1; i >= 0; i--) {
		chmin(wants[i], maxi);
		ans += min(maxi, wants[i]) + a[i];
		/*
		最大値は常にa[n]ではなく変化していく
		その頂点の葉っぱの数で変わっていく
		*/
		maxi = min(maxi, wants[i]) + a[i];
	}
	cout << ans << endl;
	return 0;
}