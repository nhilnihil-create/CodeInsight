#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

constexpr  ll COMB_MAX = 1e6+10;
vector<ll> fac(COMB_MAX); 
vector<ll> ifac(COMB_MAX); 

ll mpow(ll x, ll n){ 
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ 
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % MOD;
    return tmp * fac[a] % MOD;
}

void init()
{
	fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<COMB_MAX; i++)
	{
        fac[i+1] = fac[i]*(i+1) % MOD; 
        ifac[i+1] = ifac[i]*mpow(i+1, MOD-2) % MOD; 
    }
}


int main(int argc, char **argv)
{
	ll H, W; cin >> H >> W;
	init();
	ll res;
	if ((H + W) % 3 != 0)
		res = 0;
	else if (H > W*2 || W > H*2)
		res = 0;
	else
		res = comb((W+H)/3, H-(W+H)/3);
	std::cout << res << std::endl;
}
