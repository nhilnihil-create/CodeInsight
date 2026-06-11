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
const int N = 5e5 + 10;
const int mod = 1e9 + 7;

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
    for (int i = 1; i < N; i++)
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

long long modpow(long long n, long long k, long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}

void solve(){
    ll n,a,b;
    cin >> n >> a >> b;
    ll ans = 0;
    init();
    ans = modpow(2,n,mod);
    ll m1 = 1;
    for(ll i = n-a+1;i<=n;i++){
        m1 *= i;
        m1 %= mod;
    }
    ll m2 = 1;
    for(ll i = n-b+1;i<=n;i++){
        m2 *= i;
        m2 %= mod;
    }
    //cout << m1 << ' '<< m2<<endl;
    ll m = (m1*inv(fac[a])+m2*inv(fac[b])+1)%mod;
    ans = (ans - m + mod)%mod;
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
