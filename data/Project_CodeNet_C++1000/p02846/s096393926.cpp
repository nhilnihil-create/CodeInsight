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

using int128 = __int128_t;
using uint128 = __uint128_t;
ostream &operator<<(ostream &os, int128 value) {
    ostream::sentry s(os);
    if (s) {
        uint128 tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) --d, *d = '-';
        int len = end(buffer) - d;
        if (os.rdbuf()->sputn(d, len) != len) {
            os.setstate(ios_base::badbit);
        }
    }
    return os;
}
istream &operator>>(istream &is, int128 &val) {
    string s; is >> s;
    val = 0;
    REP(i, s.size()) if ('0' <= s[i] && s[i] <= '9') {
        val = 10 * val + s[i] - '0';
    }
    return is;
}

int main(void) {
    int128 t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

    int128 p = (a1-b1)*t1, q = (a2-b2)*t2;
    if(p > 0) p *= -1, q *= -1;

    if(p + q < 0) {
        cout << 0 << endl;
        return 0;
    }
    if(p + q == 0) {
        cout << "infinity" << endl;
        return 0;
    }

    int128 x = (-p) / (p+q);
    int128 r = (-p) % (p+q);
    cout << x*2 + !!r << endl;
    return 0;

    auto check = [&](int128 mid) {
        int128 nowx = (mid+1)/2*t1*a1 + mid/2*t2*a2;
        int128 nowy = (mid+1)/2*t1*b1 + mid/2*t2*b2;
        int128 prex = mid/2*t1*a1 + (mid-1)/2*t2*a2;
        int128 prey = mid/2*t1*b1 + (mid-1)/2*t2*b2;

        bool iscross = false;
        iscross |= prex <= prey && prey <= nowx && prex <= nowy && nowy <= nowx;
        iscross |= prey <= prex && prex <= nowy && prey <= nowx && nowx <= nowy;
        return iscross;
    };

    // REP(i, 150) dump(i, check(i));

    int128 lb = 1, ub = 1e22;
    while(ub-lb > 1) {
        int128 mid = (lb+ub)/2;
        if(check(mid)) lb = mid;
        else ub = mid;
    }
    cout << lb-1 << endl;

    return 0;
}