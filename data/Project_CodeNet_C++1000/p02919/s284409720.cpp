#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<pair<ll, ll>> vp(n);
    rep(i, n) {
        cin >> vp[i].first;
        vp[i].second = i;
    }
    sort(rall(vp));
    multiset<ll> idx;
    idx.insert(-1);
    idx.insert(-1);
    idx.insert(n);
    idx.insert(n);
    ll ans = 0;
    rep(i, n) {
        ll p = vp[i].second;
        ll v = vp[i].first;
        idx.insert(p);
        auto it = idx.lower_bound(p);
        auto rin = it; rin++;
        auto rout = rin; rout++;
        auto lin = it; lin--;
        auto lout = lin; lout--;
        ll cnt = 0;
        cnt += (*rin - p) * (*lin - *lout);
        cnt += (p - *lin) * (*rout - *rin);
        ans += cnt * v;
    }
    cout << ans << endl;
    return 0;
}
