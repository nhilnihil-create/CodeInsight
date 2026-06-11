#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

constexpr int MOD = 1000000007;

int mod(const ll &x){
    return x > 0 ? x % MOD : (x+MOD) % MOD;
}

int modm(const ll &x,const ll &m){
    return (x % MOD) * (m % MOD) % MOD;
}

int modpow(ll x, ll p) {
    int ret = 1;
    while(p > 0) {
        if (p & 1) ret = modm(ret,x);
        x = modm(x,x);
        p >>= 1;
    }
    return ret;
}

// x * modinv(d)
int modd(ll x,ll d) {
    return modm(x,modpow(d,MOD-2));
}

int main(void)
{
    IOS
    auto nc2 = [](ll x){return mod(x * (x-1) / 2);};

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    REP(i,n) cin >> v[i];
    vector<ll> t1(n), t2(n);
    REP(i,n) {
        REP(j,n) {
            if (v[i] < v[j]) {
                t1[i]++;
                if (i > j) t2[i]++;
            }
        }
        //cerr<< t1[i] << " " << t2[i] << endl;
    }
    ll ans = 0;
    REP(i,n) {
        ans = mod(ans + t1[i] * nc2(k) + t2[i]*k);
    }

    cout << ans << '\n';

    return 0;
}