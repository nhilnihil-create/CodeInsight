#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const int N = 1e6 + 10;
const ll mod = 1e9 + 7;

ll fac[N];

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for (ll i = 1; i < N; i++)
        fac[i] = fac[i - 1] * i % mod;
}

ll inv(ll a) {
	return binpow(a, mod - 2);
}

ll A(ll n, ll m) {
	return fac[n] * inv(fac[n - m]) % mod;
}

ll C(ll n, ll m) {
    return fac[n] * inv(fac[m]) % mod * inv(fac[n - m]) % mod;
}

void solve(){
    ll x,y;cin >> x >> y;
    if(y>x) swap(x,y);
    ll j = x - y;
    if((y-j)%3||y - j<0){
        cout << 0;
        return;
    }
    ll k = (y-j)/3;
    ll k2 = k+j;
    init();
    cout << A(k+k2,k+k2)*inv(A(k,k)*A(k2,k2)%mod)%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}