#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<ll> p(n), idx(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
        idx[p[i]] = i;
    }
    multiset<ll> pos;
    pos.insert(-1);
    pos.insert(-1);
    pos.insert(n);
    pos.insert(n);
    ll ans = 0;
    rrep(i, n) {
        ll m = idx[i];
        pos.insert(m);
        auto it = pos.lower_bound(m);
        auto cit = it;
        cit--;
        ll lin = *cit;
        cit--;
        ll lout = *cit;
        cit = it; cit++;
        ll rin = *cit;
        cit++;
        ll rout = *cit;
        ll cnt = 0;
        cnt += (rin - m) * (lin - lout);
        cnt += (m - lin) * (rout - rin);
        ans += cnt * (i + 1);
    }
    cout << ans << endl;
    return 0;
}
