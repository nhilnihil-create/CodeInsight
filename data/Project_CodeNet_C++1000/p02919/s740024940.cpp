#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define REP(i,m,n) for(ll i = m; i < (ll)(n); ++i)
#define rep(i,n) REP(i, 0, n)

int main() {
    ll n;
    cin >> n;
    ll p[200010];
    rep(i, n) cin >> p[i];
    ll pos[200010];
    rep(i, n) pos[p[i]] = i;
    set<ll> larger_pos;
    larger_pos.insert(pos[n]);
    ll sum = 0;

    const int invalid = -1053;

    for (ll t = n - 1; t >= 1; t--) {
        ll l1, l2, r1, r2;
        auto itr = larger_pos.lower_bound(pos[t]);

        if (itr == larger_pos.end()) {
            r1 = n;
            r2 = invalid;
        } else {
            r1 = *itr;
            itr++;
            r2 = (itr == larger_pos.end() ? n : *itr);
            itr--;
        }
        if (itr == larger_pos.begin()) {
            l1 = -1, l2 = invalid;
        } else {
            itr--;
            l1 = *itr;
            if (itr == larger_pos.begin()) l2 = -1;
            else {
                itr--;
                l2 = *itr;
                itr++;
            }
        }

        if (l2 != invalid) sum += (l1 - l2) * (r1 - pos[t]) * t;
        if (r2 != invalid) sum += (r2 - r1) * (pos[t] - l1) * t;

        larger_pos.insert(pos[t]);
    }
    
    cout << sum << endl;
    return 0;
}

