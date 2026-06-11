#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl "\n"
#define ll long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define INF 2147483647
#define LLINF 9223372036854775807LL
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define BIT(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてからつかうこと
constexpr ll MOD = 1e9 + 7;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;
ll ans = 0;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}
class hoge {
public:
    vector<ll> a, f;
    vector<ll> tmp;
    hoge() : a(N), f(N), tmp(N) {
        cin >> a >> f;
        sort(f.rbegin(), f.rend());
        sort(a.begin(), a.end());
    }

    bool isOK(ll index, ll key) {
        REP(i, N)
        tmp[i] = index / f[i];
        ll k = 0;
        REP(i, N) {
            if (a[i] > tmp[i]) {
                k += a[i] - tmp[i];
            }
        }
        dump(k, a, tmp);
        if (k <= key)
            return true;
        else
            return false;
    }

    ll binary_search(ll key) {
        ll ng = -1;       //「index = 0」が条件を満たすこともあるので、初期値は -1
        ll ok = (ll)1e15; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()
        /* ok と ng のどちらが大きいかわからないことを考慮 */
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (isOK(mid, key))
                ok = mid;
            else
                ng = mid;
        }
        return ok;
    }
};

signed main() {
    cin >> N >> K;
    hoge h;
    cout << h.binary_search(K) << endl;
}