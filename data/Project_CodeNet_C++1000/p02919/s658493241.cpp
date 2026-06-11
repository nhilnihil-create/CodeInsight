#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    cout << fixed << setprecision(16);

    ll n;
    cin >> n;
    vector<pair<ll,ll>> p(n);
    for(ll i=0; i<n; i++)
        cin >> p[i].first, p[i].second = i;
    sort(p.begin(), p.end(), greater<>());

    set<ll> pos, sop;
    pos.insert(n);
    sop.insert(1);

    ll res = 0;
    for(ll i=0; i<n; i++) {
        ll t, j;
        tie(t, j) = p[i];
        ll r = *pos.upper_bound(j);
        ll rr = r == n ? n : *pos.upper_bound(r);
        ll l = -*sop.upper_bound(-j);
        ll ll = l == -1 ? -1 : -*sop.upper_bound(-l);
        res += t * ((l - ll) * (r - j) + (rr - r) * (j - l));

        pos.insert(j);
        sop.insert(-j);
    }
    cout << res << endl;
}
