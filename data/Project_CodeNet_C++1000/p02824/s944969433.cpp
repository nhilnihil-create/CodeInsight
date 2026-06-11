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
    ll n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    sort(ALL(a), greater<>());
    ll pth = a[p-1], sump = 0, ppos = -1;
    REP(i, n) if(a[i] <= pth) sump++;

    map<ll,ll> cnt;
    REP(i, n) cnt[a[i]]++;
    dump(cnt);

    ll idx = 0;
    vector<PII> vp(cnt.size());
    for(auto i: cnt) vp[idx++] = i;

    REP(i, vp.size()) if(vp[i].first == pth) ppos = i;
    if(ppos == 0) {
        cout << n << endl;
        return 0;
    }

    vector<ll> sc(cnt.size());
    REP(i, vp.size()) sc[i] = (m-vp[i].first) * vp[i].second;
    vector<ll> rui(sc);
    FOR(i, 1, vp.size()) rui[i] += rui[i-1];
    dump(sc);
    dump(rui);

    vector<ll> num(cnt.size());
    REP(i, cnt.size()) num[i] = vp[i].second;
    FOR(i, 1, cnt.size()) num[i] += num[i-1];
    dump(num);

    ll sum = 0, ret = 0;
    ll all = 0;
    ll pos = 0;
    REP(i, vp.size()) {
        sum += vp[i].second;
        all = vp[i].first; 
        chmax(pos, i+1);
        while(pos < (ll)vp.size() && all+sc[pos]/vp[pos].second >= m) pos++;
        ll can = num[num.size()-1]-num[ppos] + sum;
        dump(i, vp[i], can);
        if(vp[i].first >= pth) {
            ret += vp[i].second;
            continue;
        }
        if(vp[i].first + m < pth) continue;
        if(can >= v) {
            ret += vp[i].second;
            dump("ok");
        } else {
            // (v-can)問 を M人 → sump-sum問に振り分ける
            // i.first + m 点以下になるようにする
            // [i+1, pos) → m側
            ll tmp = (num[pos-1] - num[i]) * m;
            // [pos, pth] → sc側
            tmp += rui[ppos] - rui[pos-1] + (num[ppos] - num[pos-1]) * all;
            dump(tmp, (v-can)*m);

            if(tmp >= (v-can)*m) {
                ret += vp[i].second;
                dump("okb");
            }
        }
    }
    cout << ret << endl;

    return 0;
}