#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;

constexpr ll MOD = 998244353;

ll N;

int main(void) {
    cin >> N;

    vector<ll> D(100000);

    ll a;
    cin >> a;
    if (a != 0) {
        cout << 0 << endl;
        return 0;
    }
    D[a]++;
    
    ll d_max = 0;
    REP(i, 1, N) {
        cin >> a;
        D[a]++;
        d_max = max(d_max, a);
    }

    if (D[0] != 1) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    for(int i = 2; i <= d_max; ++i) {
        if (D[i] == 0) {
            ans = 0;
            break;
        }

        ll t = 1;
        for(int k = 0; k < D[i]; ++k) {
            t = (t * D[i - 1]) % MOD;
        }

        ans = (ans * t) % MOD;
    }

    cout << ans << endl;
    return 0;
}