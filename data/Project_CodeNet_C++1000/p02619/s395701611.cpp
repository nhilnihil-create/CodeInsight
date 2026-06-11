#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
using lc = complex<double>;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    constexpr double PI = acos(-1);
    cout << fixed << setprecision(32);
    cin.tie(0); ios::sync_with_stdio(false);

    ll d;
    cin >> d;
    ll a = 26;
    vector<ll> c(a);
    vector<vector<ll>> s(d, vector<ll>(a));
    for(auto &e: c) cin >> e;
    for(auto &l: s) for(auto &e: l) cin >> e;
    
    vector<ll> t(d);
    for(auto &e: t) cin >> e, e--;

    vector<ll> last(a, -1);
    ll score = 0;
    for(ll i=0; i<d; i++) {
        last[t[i]] = i;

        score += s[i][t[i]];
        for(ll j=0; j<a; j++)
            score -= c[j] * (i - last[j]);
        cout << score << endl;
    }
}