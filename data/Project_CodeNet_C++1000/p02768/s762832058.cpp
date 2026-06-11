#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
ll com(ll n, ll r){
	ll ret = 1;
	for(ll i = n - r + 1; i <= n; i++){
		ret *= i;
		ret %= mod;
	}
    for(ll i = 1LL; i <= r; i++){
    	ret *= modpow(i, mod - 2);
    	ret %= mod;
    }
    return ret;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = modpow(2LL, n) - 1LL;
    ans -= com(n, a);
    ans -= com(n, b);
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout << ans << endl;
    return 0;
}
