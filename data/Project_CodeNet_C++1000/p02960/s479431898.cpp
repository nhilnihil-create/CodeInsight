#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (ll i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;
typedef pair<int, int> P;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll ans = 0;
    string S;
    cin >> S;

    int len = (int)S.size();

    vector<ll> cntb(13, 0);
    cntb[0] = 1;
    rep(i, len) {
        vector<ll> cnt(13, 0);
        if (S[len - i - 1] == '?') {
            rep(j, 10) {
                ll m = (j * mod_pow(10, i, 13));
                cnt[m % 13]++;
            }
        }
        else {
            ll d = S[len - i - 1] - '0';
            ll m = (d * mod_pow(10, i, 13));
            cnt[m % 13]++;
        }
        if (i == len - 1) {
            rep(j, 13) {
                ans += (cntb[j] * cnt[(13 + 5 - j) % 13]) % MOD;
                ans %= MOD;
            }
        }

        vector<ll> cntt(13, 0);
        rep(j, 13) {
            rep(k, 13) {
                cntt[(k + j) % 13] += (cntb[j] * cnt[k]) % MOD;
                cntt[(k + j) % 13] %= MOD;
            }
        }
        rep(j, 13) {
            cntb[j] = cntt[j];
        }
    }

    cout << ans % MOD << endl;
    return 0;
}