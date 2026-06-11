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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    vector<pair<ll, ll>> opr;
    ll low = a[0], high = a[n - 1];
    reps(i, 1, n - 1) {
        if (a[i] > 0) {
            opr.push_back(make_pair(low, a[i]));
            low -= a[i];
        }
        else {
            opr.push_back(make_pair(high, a[i]));
            high -= a[i];
        }
    }
    opr.push_back(make_pair(high, low));
    printf("%lld\n", high - low);
    rep(i, sz(opr)) printf("%lld %lld\n", opr[i].first, opr[i].second);
    return 0;
}
