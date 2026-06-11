#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

ll modpow(ll a, ll n){
    if(n == 1)return a;
    if(n % 2 == 1) return (a * modpow(a, n-1)) % MOD;
    ll t = modpow(a, n/2);
    return (t * t) % MOD;
}

ll ncr(ll n, ll r){
    ll x = 1, y = 1;
    rep(i, r){
        x *= n-i;
        y *= i+1;
        x %= MOD;
        y %= MOD;
    }
    y = modpow(y, MOD-2);
    return x*y % MOD;
}

int main()
{
    ll n, a, b; cin >> n >> a >> b;
    ll ans = modpow(2, n)-1;
    ans += MOD-ncr(n, a);
    ans += MOD-ncr(n, b);
    ans %= MOD;
    cout << ans << endl;
    system("pause");
}

