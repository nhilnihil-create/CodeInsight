#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
bool cmp(int a,int b){return a>b;}
const ll N = 5e5 + 10;
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

//const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

void solve(){
     ll n,k;cin >> n >> k;
     init();
     for(ll i = 1;i<=k;i++){
     if(n-k+1<i){cout << 0 <<endl;continue;}
     ll ans = C(n-k+1,i)*C(k-1,i-1);
     ans %= mod;
     cout << ans <<endl;
     }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}