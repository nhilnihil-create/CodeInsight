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
    string s;
    cin >> n >> s;

    vector<ll> v(n);
    REP(i, n) v[i] = s[i]-'0'-1;

    auto check = [&] {
        ll sum = 0;
        REP(i, n) if(v[i]==1) {
            ll a = n-1, b = i, prod = 1;
            while(a > 0 || b > 0) {
                if(a%2 < b%2) prod = 0;
                a /= 2;
                b /= 2;
            }
            sum ^= prod;
        }
        return sum;
    };

    if(check()) {
        cout << 1 << endl;
    } else {
        REP(i, n) if(v[i] == 1) {
            cout << 0 << endl;
            return 0;
        }
        REP(i, n) v[i] /= 2;
        if(check()) cout << 2 << endl;
        else cout << 0 << endl;
    }

    return 0;
}