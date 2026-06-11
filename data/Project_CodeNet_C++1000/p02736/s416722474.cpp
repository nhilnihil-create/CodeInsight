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
    string s;
    cin >> n >> s;

    // 入力がaのときの偶奇を返す
    auto func = [](vector<ll> a) {
        const ll n = a.size();
        ll sum = 0;
        REP(i, n) if(a[i]==1) sum ^= (((n-1)&i)==i);
        return sum;
    };

    vector<ll> a(n);
    REP(i, n) a[i] = s[i]-'1';

    if(func(a) == 1) {
        cout << "1\n";
    } else {
        bool exist = false;
        REP(i, n) if(a[i]==1) exist = true;
        if(exist) {
            cout << "0\n";
        } else {
            REP(i, n) if(a[i]==2) a[i]--;
            if(func(a)) cout << "2\n";
            else cout << "0\n";
        }
    }

    return 0;
}