#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<stack>
#include<unordered_map>
#include<bitset>
#include<limits>
#include<complex>
#include<array>
using namespace std;
#define rrep(i,m,n) for(int (i)=(int)(m);(i)>=(int)(n);(i)--)
#define rep(i,m,n) for(int (i)=(int)(m);i<(int)(n);i++)
#define REP(i,n) rep(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
#define M_PI 3.1415926535897932LL;
typedef pair<ll, ll> P;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;
constexpr long double EPS = 1e-10;
typedef vector<ll> Array;

//nCrとか
class Combination {
public:
	Array fact;
	Array inv;
	ll mod;
	ll mod_inv(ll x) {
		ll n = mod - 2LL;
		ll res = 1LL;
		while (n > 0) {
			if (n & 1) res = res * x % mod;
			x = x * x % mod;
			n >>= 1;
		}
		return res;
	}
	//if n >= mod use lucas 
	ll nCr(ll n, ll r) {
		if (n < r)return 0;
		if (n < mod)return ((fact[n] * inv[r] % mod) * inv[n - r]) % mod;
		
		ll ret = 1;
		while (n || r) {
			ll _n = n % mod, _r = r % mod;
			n /= mod; r /= mod;
			(ret *= nCr(_n, _r)) %= mod;
		}
		return ret;
	}
	ll nPr(ll n, ll r) {
		return (fact[n] * inv[n - r]) % mod;
	}
	ll nHr(ll n, ll r) {
		return nCr(r + n - 1, r);
	}
	Combination(ll _n, ll _mod) {
		mod = _mod;
		ll n = min(_n+1, mod);
		fact.resize(n);
		fact[0] = 1;
		REP(i, n-1) {
			fact[i + 1] = (fact[i] * (i + 1LL)) % mod;
		}
		inv.resize(n);
		inv[n-1] = mod_inv(fact[n-1]);
		for (int i = n-1; i > 0; i--) {
			inv[i - 1] = inv[i] * i % mod;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n;
	string s;
	cin >> s;
	Array a(n);
	REP(i, n)a[i] = s[i] - '0' - 1;
	Combination comb(n, 2);
	ll ans = 0;
	ll cnt = 0;
	REP(i, n) if (a[i] == 1)ans += comb.nCr(n-1, i), cnt++;
	if (cnt) {
		cout << ans % 2 << endl;
		return 0;
	}
	REP(i, n) if (a[i] == 2)ans += comb.nCr(n-1, i);
	cout << ans % 2 * 2 << endl;
  
	return 0;
}
