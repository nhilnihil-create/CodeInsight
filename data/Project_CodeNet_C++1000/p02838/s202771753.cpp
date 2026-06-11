#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    map<ll, ll> mp;
    rep(bit, 61) {
        ll num = 1ll<<bit;
        int cnt = 0;
        rep(i, n) {
            if (num & a[i]) cnt++;
        }
        mp[num%MOD] = cnt;
    }
    ll ans = 0;
    for(const auto& m: mp) {
        if (m.se) {
            // debug(m.fi, m.se, m.fi * m.se * (n-m.se));
            ans += (((m.fi%MOD) * m.se)%MOD * (n-m.se))%MOD;
            ans %= MOD;
        }
    }
    cout << ans%MOD << endl;

}