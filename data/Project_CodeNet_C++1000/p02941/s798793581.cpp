#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

int main(void) {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];

    ll ans = 0;
    priority_queue<PII> que;
    REP(i, n) if(a[i] != b[i]) que.push({b[i], i});
    while(que.size()) {
        ll val, i;
        tie(val, i) = que.top(); que.pop();

        // b[i] - t*num <= t \iff (b[i]-t)/t <= num であるような最大のnum
        // b[i] - t*num <= a[i] \iff (b[i]-a[i])/t <= num であるような最大のnum
        ll t = b[(i+n-1)%n] + b[(i+1)%n];
        ll num = min((b[i]-1)/t, (b[i]-a[i]+t-1)/t);
        dump(b[i], a[i], t, num);
        b[i] -= t * num;
        ans += num;
        dump(b);

        if(num == 0) {
            cout << "-1\n";
            return 0;
        }
        if(b[i] != a[i]) que.push({b[i], i});
    }

    cout << ans << endl;

    return 0;
}