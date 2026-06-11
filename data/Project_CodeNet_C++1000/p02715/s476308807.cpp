#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
const long long INF = 1LL << 60;
const int MOD = 1e9 + 7;

ll modpow(ll a, ll n, ll mod = MOD) {
    ll rtn = 1;
    while (n > 0) {
        if (n & 1) rtn = rtn * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return rtn;
}

ll modulo(ll a,ll mod = MOD){
    return (a % mod + mod) % mod;
}

int main(){
	int N,K;
	cin >> N >> K;

	ll ans = 0;
	std::vector<ll> found(K+1);
	rep(i,K){
		//consider gcd(....) = (K-i)
		found.at(K-i)= modpow(K/(K-i),N,MOD);

		rep2(j,2,K/(K-i)+1){
			found.at(K-i) -= found.at(j*(K-i));
		}
		ans += found.at(K-i)*(K-i);
	}

	cout << ans % MOD << endl;
	return 0;

}