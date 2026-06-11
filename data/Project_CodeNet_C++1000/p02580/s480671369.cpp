#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second

using vint = vector<int>;
using pint = pair<int, int>;
using vpint = vector<pint>;

template <typename A, typename B>
inline void chmin(A& a, B b) {
    if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A& a, B b) {
    if (a < b) a = b;
}

template <class A, class B>
ostream& operator<<(ostream& ost, const pair<A, B>& p) {
    ost << "{" << p.first << "," << p.second << "}";
    return ost;
}

template <class T>
ostream& operator<<(ostream& ost, const vector<T>& v) {
    ost << "{";
    for (int i = 0; i < v.size(); i++) {
        if (i) ost << ",";
        ost << v[i];
    }
    ost << "}";
    return ost;
}

inline int topbit(unsigned long long x) {
    return x ? 63 - __builtin_clzll(x) : -1;
}

inline int popcount(unsigned long long x) {
    return __builtin_popcountll(x);
}

inline int parity(unsigned long long x) {
    return __builtin_parity(x);
}

signed main() {
    int H, W, M;
    cin >> H >> W >> M;

    vint cntH(H), cntW(W);
    set<pint> s;
    rep(i, M) {
        int h, w;
        cin >> h >> w;
        h--;
        w--;
        cntH[h]++;
        cntW[w]++;
        s.insert(pint(h, w));
    }

    vint idxH, idxW;
    {
        int ma = *max_element(all(cntH));
        rep(i, H) if (cntH[i] == ma) idxH.pb(i);
    }
    {
        int ma = *max_element(all(cntW));
        rep(i, W) if (cntW[i] == ma) idxW.pb(i);
    }

    auto tmp = [&]() {
        if ((int)idxH.size() * idxW.size() > M) {
            return true;
        }
        for (auto y : idxH)
            for (auto x : idxW)
                if (s.find(pint(y, x)) == s.end()) return true;
        return false;
    }();

    int ans = cntH[idxH.front()] + cntW[idxW.front()];
    if (!tmp) ans--;
    cout << ans << endl;
    return 0;
}