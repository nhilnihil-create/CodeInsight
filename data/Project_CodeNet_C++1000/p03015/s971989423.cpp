#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }

typedef pair<ll, ll> P;

ll modnum = 1000000000+7;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    string l; cin >> l;
    ll ans = 0;
    ll tmpans = 1;
    rep(i, l.size()) {
        int n = l[i] - '0';
        if(n == 1) {
            ll x = modpow(3, l.size()-1-i, modnum);
            ans += x * tmpans;
            ans %= modnum;

            tmpans *= 2;
            tmpans %= modnum;
        }
    }

    ans += tmpans;
    ans %= modnum;

    cout << ans << endl;
    return 0;

}

// 161999316
// 162261460
//    524288