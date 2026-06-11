#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <climits>
#include <cstring>

using namespace std;

#define int long long
#define rep(i, n) for (int i=0;i<(int)(n);++i)
#define rep1(i, n) for (int i=1;i<=(int)(n);++i)
#define range(i, l, r) for (int i=l;i<(int)(r);++i)
#define rrange(i, l, r) for (int i=r-1;i>=(int)(l);--i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using vi=vector<int>;
using pii=pair<int, int>;
using ll=long long;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}

const int mod = 1e9 + 7;

ll inv[200010];
ll fac[200010], fac_inv[200010];

ll C(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return ((fac[n] * fac_inv[k] % mod) * fac_inv[n - k]) % mod;
}

void comb_init()
{
	int N = 200005;
	inv[1] = 1;

	for (int i = 2; i <= N; ++i) {
		inv[i] = mod - (mod / i) * inv[mod % i] % mod;
	}

	fac[0] = fac_inv[0] = 1;

	for (int i = 1; i <= N; ++i) {
		fac[i] = (fac[i - 1] * i) % mod;
		fac_inv[i] = (fac_inv[i - 1] * inv[i]) % mod;
	}
}

inline ll mod_pow(ll a, ll x, ll m)
{
	if (x <= 0) return 1;

	ll res = mod_pow(a, x / 2, m);

	res *= res;
	res %= m;

	if (x % 2) {
		res *= a;
		res %= m;
	}

	return res;
}


signed main()
{
	comb_init();

	int N, K; cin >> N >> K;

	int R = N - K, B = K;

	range(i, 1, K + 1) {
		int ans = 1;
		
		ans *= C(B - 1, B - i);
		ans *= C(R + 1, i);
		ans %= mod;

		cout << ans << endl;
	}
}

