#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

vector<ll> fac(300001); 
vector<ll> ifac(300001); 

ll mpow(ll x, ll n){ //x^
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % MOD;
    return tmp * fac[a] % MOD;
}

void init()
{
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<300000; i++){
        fac[i+1] = fac[i]*(i+1) % MOD; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, MOD-2) % MOD; // k!^{M-2} (mod M) ←累乗にmpowを採用
	}
}

int main(int argc, char **argv)
{
	ll N, K; cin >> N >> K;

	ll res{0};
	ll R = N - K;
	ll B = R + 1;
	init();
	for (ll i = 1; i <= K; ++i)
	{
		std::cout << (comb(B, i) * comb(K-1, i-1))%MOD  << std::endl;
	}
}
