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
using pq = priority_queue<int>;
template<class T>
using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int under = (1 << 31);
int upper = under - 1;
ll UNDER = (1LL << 63);
ll UPPER = UNDER - 1;
const int MOD = 1e9 + 7;
const long double pi = 3.141592653589793;
ll modpow(ll a, ll b, ll M) {
	ll res = 1;
	for (; b > 0; b >>= 1) {
		if (b & 1) res = (res * a) % M;
		a = a * a % M;
	}
	return res;
}
int main(){
	int n, k;
	cin >> n >> k;
	VL gcds(k + 1);
	for (int i = k; i >= 1; i--) {
		ll tmp = k / i; // gcdがtmpの倍数になるようなものの個数
		ll tmp2 = modpow(tmp, n, MOD); // tmp^n個だけある(mod 1e9+7)
		for (int j = i + i; j <= k; j += i) { // tmpの倍数ではあるがtmpではないものを引く
			tmp2 -= gcds[j];
		}
		gcds[i] = tmp2;
	}
	ll ans = 0;
	rep1(i, k) {
		ans += i * gcds[i];
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}