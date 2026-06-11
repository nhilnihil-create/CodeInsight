#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
const ll INF = 1LL<<60;

int main(void) {
    ll k, q;
    cin >> k >> q;
    vector<ll> d0(k);
    REP(i, k) cin >> d0[i];

    REP(i, q) {
        ll n, x, mo;
        cin >> n >> x >> mo;
        x %= mo;

        ll sum = 0;
        vector<ll> d(d0);
        REP(j, k) d[j] %= mo, sum += d[j];

        ll ret = 0;
        REP(j, k) if(d[j] == 0) ret += (n-1)/k + (j < (n-1)%k);
        
        ll last = (n-1)/k*sum + x;
        REP(j, (n-1)%k) last += d[j];
        ret += last/mo - x/mo;
        
        cout << n-1 - ret << "\n";
    }

    return 0;
}