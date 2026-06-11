#include <bits/stdc++.h>

const int INF = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

ll powmod(ll n, ll x)
{
    vector<ll> vll(32);
    vll[0] = n;
    FOR(i, 1, 32)
    {
        vll[i] = (vll[i - 1] * vll[i - 1]) % MOD;
    }
    ll ret = 1;
    int cnt = 0;
    while (x > 0) {
        if (x & 1) {
            ret = (ret * vll[cnt]) % MOD;
        }
        x >>= 1;
        cnt++;
    }
    return ret;
}

long long fac[2000001];
struct Comb {
    Comb()
    {
        fac[0] = fac[1] = 1;
        for (int i = 2; i < 2000001; i++) {
            fac[i] = fac[i - 1] * i % MOD;
        }
    }

    long long COM(int n, int k)
    {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        ll ret = fac[n];
        ret = (ret * powmod(fac[k], MOD - 2)) % MOD;
        ret = (ret * powmod(fac[n - k], MOD - 2)) % MOD;
        return ret;
    }

    ll PERM(int n, int k)
    {
        if (n < k)
            return 0;
        ll ret = fac[n];
        ret = (ret * powmod(fac[n - k], MOD - 2)) % MOD;
        return ret;
    }
};

int main()
{
    
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    Comb C;
    vector<ll> end(n+2,0);
    FOR(i,1,n+2){
        end[i]=end[i-1]+n-i+1+MOD;
        end[i]%=MOD;
    }
    for (ll i = k; i <= n + 1; i++) {
        ll first=i*(i-1)/2;
        first%=MOD;
        ans += end[i]-first+MOD+1;
        ans %= MOD;
    }
    cout << ans << endl;
}