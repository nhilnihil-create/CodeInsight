#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
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
    int N, K;
    cin >> N >> K;
    vector<int> v(K+1);

    int ans = 0;
    RREP(i,K) {
        if (i == 0) break;
        int g = modpow(K/i,N);
        for (size_t j = i*2; j <= K; j += i)
        {
            g = mod(g-v[j]);
        }
        // cerr << g << endl;
        ans = mod(ans+modm(g,i));
        v[i] = g;
    }

    cout << ans << '\n';

    return 0;
}