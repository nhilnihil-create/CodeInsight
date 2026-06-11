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
#define RANGE(a, start_index, num)  (a).begin()+(start_index),(a).begin()+(num)

vector<int> mod13 = { 1,10,9,12,3,4 };

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
	static ll memo[100001][13] = {};
	memo[0][0] = 1;
	int n = SZ(s);
	FOR(i, 1, n) {
		if (s[n - i] == '?' ) {
			ll tmp = mod13[(i - 1) % 6];
			FOR(j, 0, 12) {
				FOR(k, 0, 9) {
					memo[i][(j + k*tmp) % 13] += memo[i - 1][j];
					memo[i][(j + k*tmp) % 13] %= MOD;
				}
			}
		}
		else {
			ll num = s[n - i] - '0';
			ll tmp = mod13[(i - 1) % 6];
			FOR(j, 0, 12) {
				memo[i][(j+num*tmp)%13] += memo[i - 1][j];
				memo[i][(j + num*tmp) % 13] %= MOD;
			}
		}
	}
	pv(memo[n][5])
}