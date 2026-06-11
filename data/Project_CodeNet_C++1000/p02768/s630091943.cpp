#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setbits(x) __builtin_popcount(x)
#define zerobits(x) __builtin_ctz(x)
#define setbitsll(x) __builtin_popcountll(x)
#define zerobitsll(x) __builtin_ctzll(x)
#define inf 1e18
#define ps(x,y) fixed<<setprecision(y)<<x

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef map<int,int> mii;

const int MOD = 1e9+7;
const int maxN = 2e5+1;
// ll fact[maxN];

// void factorial () {
// 	fact[0] = 1;
// 	for (int i = 1;i < maxN;++i) {
// 		fact[i] = (ll)i*fact[i-1];
// 	}
// }

ll power (ll x,ll n) {
	ll res = 1;
	while (n) {
		if (n&1) {
			res = (res*x)%MOD;
		}
		n = n/2;
		x = (x*x)%MOD;
	}
	return res;
}

ll modInverse (ll x) {
	return power(x,MOD-2);
}

ll nCr (ll n,ll k) {
	if (k > n) {
		k = n-k;
	}
	ll res = 1;
	for (ll i = 0;i < k;++i) {
		res = (res*(n-i))%MOD;
		res = (res*(modInverse(i+1)))%MOD;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// factorial();
	ll n,a,b;
	cin >> n >> a >> b;
	ll ans = power(2,n)-1;
	if (a <= n) {
		ans = (ans-nCr(n,a)+MOD)%MOD;
	}
	if (b <= n) {
		ans = (ans-nCr(n,b)+MOD)%MOD;
	}
	cout << ans << '\n';
	return 0;
}

