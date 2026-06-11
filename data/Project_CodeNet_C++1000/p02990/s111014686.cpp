#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define DEBUG(x) std::cerr << #x << " : " << (x) << std::endl;

struct Comb
{
	const long long mod;
	vector<long long> fac, ifac;

	Comb(long long n, long long m) : mod(m)
	{
		fac.resize(n+1);
		ifac.resize(n+1);

		fac[0] = 1;
		ifac[0] = 1;
		for (long long i = 0; i < n; ++i)
		{
			(fac[i+1] = fac[i]*(i+1)) %= mod;
			(ifac[i+1] = ifac[i]*mpow(i+1, mod-2)) %= mod;
		}
		
	}

	long long mpow(long long x, long long n)
	{ 
		long long ans = 1;
		while(n != 0){
			if(n&1) ans = ans*x % mod;
			x = x*x % mod;
			n = n >> 1;
		}
		return ans;
	}

	long long comb(long long a, long long b)
	{ 
		if(a == 0 && b == 0)return 1;
		if(a < b || a < 0)return 0;
		long long tmp = ifac[a-b]* ifac[b] % mod;
		return tmp * fac[a] % mod;
	}
};


int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Comb cb(2010, MOD);
	ll N, K; cin >> N >> K;

	for (ll i = 1; i <= K; ++i)
	{
		ll tmp = cb.comb(N-K+1, i) * cb.comb(K-1, i-1);
		std::cout << tmp % MOD << std::endl;
	}
	return 0;
}
