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

ll n, m, v, p;
vector<ll> a;

bool f(ll idx) {
    if (idx < p) return true;
    if (a[p - 1] > (a[idx] + m)) return false;
    ll cnt = (p - 1) * m + (n - idx - 1) * m + m;
    reps(i, p - 1, idx) {
        cnt += (a[idx] + m) - a[i];
    }
    return cnt >= (m * v);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    cin >> n >> m >> v >> p;
    a.resize(n);
    rep(i, n) cin >> a[i];
    sort(all(a), greater<ll>());
    ll l = 0, r = n;
    while((l + 1) < r) {
        ll m = (l + r) / 2;
        if (f(m)) l = m;
        else r = m;
    }
    printf("%lld\n", l + 1);
    return 0;
}
