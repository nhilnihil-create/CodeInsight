#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
#define Would
#define you
#define all(n)  n.begin(),n.end()
#define rall(n) n.rbegin(),n.rend()
typedef long long ll;
//typedef complex<double>P;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const double EPS = 1e-10;
const double pi = acos(-1);//3.1415926535897932384626433832795028...
const ll SIZE = 1 << 17;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, alp[30];
ll fac[200005], finv[200005], inv[200005];
vector<ll>dij;
struct edge { ll to, cost; };
vector<vector<edge> >G;

ll mod_pow(ll a, ll b) {
	ll res = 1, mul = a;
	for (int i = 0; i < 31; ++i) {
		if (b >> i & 1) {
			res *= mul;
			res %= MOD;
		}
		mul = (mul * mul) % MOD;
	}
	return res;
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v) {
	for (auto &e : t) fill_v(e, v);
}

template<typename T>
void outp(vector<T>v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
		if (i != v.size() - 1) { cout << " "; }
	}
}

double add(double a, double b) {
	if (abs(a + b) < EPS*(abs(a) + abs(b))) { return 0; }
	return a + b;
}


//↑template↑



ll n, k[200005], ans[200005];
vector<int>v;
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
	}

	for (int i = n; i > 0; --i) {
		ll mon = 0;
		for (int j = 2 * i; j <= n; j += i) { mon += ans[j]; }
		if (mon % 2 != k[i]) {
			ans[i] = 1;
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (ans[i]) { v.push_back(i); }
	}
	cout << v.size() << endl;
	for (auto i : v) { cout << i << " "; }
	cout << endl;
}