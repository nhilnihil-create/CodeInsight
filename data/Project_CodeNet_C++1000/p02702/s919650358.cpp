#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define dump(x)  cout << #x << " = " << (x) << endl;	//debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, l, r)  (a).begin()+(l),(a).begin()+(r)

ll modpow(ll a, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	string s;
	cin >> s;
	int n = SZ(s);
	vector<ll> memo(n);
	memo[0] = s[n-1]-'0';
	FOR(i, 1, n - 1) {
		ll tmp = s[n - 1 - i] - '0';
		memo[i] = (memo[i - 1] + modpow(10LL, i, 2019LL)*tmp % 2019)%2019;
	}
	map<ll, int> memo2;
	memo2[0] = 1;
	FOR(i, 0, n - 1) {
		memo2[memo[i]]++;
	}
	ll res = 0;
	for(auto itr = memo2.begin(); itr != memo2.end(); itr++) {
		ll tmp = itr->second;
		res += tmp*(tmp - 1) / 2;
	}
	pv(res)
	return(0);
}