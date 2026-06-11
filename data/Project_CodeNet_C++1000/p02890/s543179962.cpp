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
#ifdef DEBUG_ 
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

int main(void) {
    ll n;
    cin >> n;
    vector<ll> a(n), cnt(n);
    REP(i, n) cin >> a[i], a[i]--, cnt[a[i]]++;

    sort(ALL(cnt));
    vector<ll> rui(cnt);
    FOR(i, 1, n+1) rui[i] += rui[i-1];

    vector<ll> able(n+1);
    FOR(i, 1, n+1) {
        ll itr = upper_bound(ALL(cnt), i) - cnt.begin();
        able[i] = ((itr==0 ? 0 : rui[itr-1]) + (n-itr)*i) / i;
    }

    FOR(i, 1, n+1) {
        ll lb = 0, ub = n+1;
        auto check = [&](ll mid) { return i <= able[mid]; };
        while(ub-lb>1) {
            ll mid = (lb+ub)/2;
            if(check(mid)) lb = mid;
            else ub = mid;
        }
        cout << lb << "\n";
    }
    cout << flush;

    return 0;
}